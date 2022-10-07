FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y && apt-get -y install mariadb-server
COPY tools/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/data.sql /data.sql
RUN service mysql start && mysql < data.sql

# RUN mysqld_safe