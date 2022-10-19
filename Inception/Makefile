all : 
	mkdir ../data
	mkdir ../data/mariadb
	mkdir ../data/wordpress
	docker-compose -f ./srcs/docker-compose.yml up
clean :
	rm -rf ../data
	docker-compose -f ./srcs/docker-compose.yml down
	
re : clean all