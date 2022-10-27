NAME=Inception
DB_PATH=/home/yson/data

all : $(NAME)
	
$(NAME) :
	mkdir -p $(DB_PATH)
	mkdir -p $(DB_PATH)/mariadb
	mkdir -p $(DB_PATH)/wordpress
	make up

init :
	sudo echo "127.0.0.1	yson.42.fr" >> /etc/hosts

up : 
	docker-compose -f ./srcs/docker-compose.yml up --build

down : 
	docker-compose -f ./srcs/docker-compose.yml down

clean : down
	sudo rm -rf $(DB_PATH)

fclean : clean
	sudo bash remove.sh
	
re : fclean all

.PHONY	: init all clean fclean re down