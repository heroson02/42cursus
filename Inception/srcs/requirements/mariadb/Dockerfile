FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y && apt-get -y install mariadb-server
COPY tools/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/sql_init.sh /sql_init.sh
RUN mysql < data.sql
# RUN chmod +x sql_init.sh
# RUN bash sql_init.sh
RUN service mysql start

