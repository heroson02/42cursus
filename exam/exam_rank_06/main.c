#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_clients {
    int     id;
    char    msg[1024];
} t_clients;

t_clients   clients[1024];
fd_set      readfds, writefds, active;	//fd를 저장하기 위해서 사용하는 구조체이다. 각 fd_set당 FD_SETSIZE만큼의 fd를 저장할 수 있으며, 보통 1024개이다.
int         fdMax = 0, idNext = 0;
char        bufferRead[120000], bufferWrite[120000];

void    ftError(char *str) {			//str을 받고 에러를 출력하는 함수.
    if (str)
        write(2, str, strlen(str));		//인자가 들어왔을 때는 그에 맞는 문자열을 stderr로 출력.
    else
        write(2, "Fatal error", strlen("Fatal error"));	//그 외의 경우에는 fatal Error를 출력
    write(2, "\n", 1);
    exit(1);	//개행과 함께 exit한다.
}

void    sendAll(int not) {
    for(int i = 0; i <= fdMax; i++)	//fd 전체를 순회한다.
        if(FD_ISSET(i, &writefds) && i != not)	//writefds에 i가 존재하며, i가 not이 아닐 때
            send(i, bufferWrite, strlen(bufferWrite), 0);	//bufferWrite를 i에 전송한다.
}

int main(int ac, char **av) {
    if (ac != 2)	//프로그램에 인자가 1개만 들어와야 한다.
        ftError("Wrong number of arguments");

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);	//소켓을 생성하고 fd를 반환한다. AF_INET은 IPV4를 사용하기 위해서, SOCK_STREAM는 TCP 프로토콜로 통신하기 위해서 사용한다.
    if (sockfd < 0)
        ftError(NULL);

    FD_ZERO(&active);	//FD_ZERO를 사용하여 fd_set인 active을 초기화한다.
    bzero(&clients, sizeof(clients)); //클라이언트 또한 0으로 초기화한다.
    fdMax = sockfd;		//fdMax는 소켓 생성을 통해 만들어진 fd를 저장한다.
    FD_SET(sockfd, &active);	//sockfd를 fd_set으로 변환시킨다.

    struct sockaddr_in  servaddr;	//sockaddr_in은 ipv4주소를 표현하기 위하여 사용되는 구조체이다. 
    socklen_t           len;
   	bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;	//ipv4를 사용하기 때문에 AF_INET을 sin family에 사용.
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1 //sin_addr에 ip 주소를 저장하며, s_addr는 주소 저장 전용 구조체이다.
	servaddr.sin_port = htons(atoi(av[1]));	//포트번호를 넣는 곳이며, 프로그램 인자로 들어온다.

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) //소켓을 servaddr에 맞게 바인딩한다. 
        ftError(NULL);
    if (listen(sockfd, 10) < 0)	//소켓을 통해 들어오는 연결을 기다린다. 최대 10개를 받는다.
        ftError(NULL);

    while(1) {
        readfds = writefds = active;
        if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0)
            continue;
        for(int fdI = 0; fdI <= fdMax; fdI++) {
            if (FD_ISSET(fdI, &readfds) && fdI == sockfd) {
                int connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
                if (connfd < 0)
                    continue;
                fdMax = connfd > fdMax ? connfd : fdMax;
                clients[connfd].id = idNext++;
                FD_SET(connfd, &active);
                sprintf(bufferWrite, "server: client %d just arrived\n", clients[connfd].id);
                sendAll(connfd);
                break;
            }
            if (FD_ISSET(fdI, &readfds) && fdI != sockfd) {
                int res = recv(fdI, bufferRead, 65536, 0);
                if (res <= 0) {
                    sprintf(bufferWrite, "server: client %d just left\n", clients[fdI].id);
                    sendAll(fdI);
                    FD_CLR(fdI, &active);
                    close(fdI);
                    break;
                }
                else {
                    for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++) {
                        clients[fdI].msg[j] = bufferRead[i];
                        if (clients[fdI].msg[j] == '\n') {
                            clients[fdI].msg[j] = '\0';
                            sprintf(bufferWrite, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
                            sendAll(fdI);
                            bzero(&clients[fdI].msg, strlen(clients[fdI].msg));
                            j = -1;
                        }
                    }
					break;
                }
            }
        }
    }
}