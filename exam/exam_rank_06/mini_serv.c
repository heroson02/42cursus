#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>			//넷디비헤더
#include <netinet/in.h>		//뎃인터넷/인헤더

typedef struct s_client
{
	int fd;
	char msg[1024];
}	t_client;

t_client clients[1024];

void	ft_Errror(char *str)
{
	if (str)
		write(2, str, strlen(str));
	else
		write(2, "Fatal errror", strlen("Fatal error"));
	write(2, "\n", 1);
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_Errror("Wrong number of arguments");
	
	
}