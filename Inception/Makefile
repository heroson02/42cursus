all : 
	mkdir /home/yson/data/mariadb
	mkdir /home/yson/data/wordpress
	# mkdir /Users/yson/data/mariadb
	# mkdir /Users/yson/data/wordpress
	docker-compose -f ./srcs/docker-compose.yml up --build -d
clean :
	bash remove.sh
	# rm -rf /Users/yson/data/mariadb
	# rm -rf /Users/yson/data/wordpress
	rm -rf /home/yson/data/mariadb
	rm -rf /home/yson/data/wordpress