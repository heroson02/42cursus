all : 
	mkdir ../data
	mkdir ../data/mariadb
	mkdir ../data/wordpress
	docker-compose -f ./srcs/docker-compose.yml up --build -d
clean :
	docker-compose -f ./srcs/docker-compose.yml down
	rm -rf ../data