FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y 
RUN apt-get -y install mariadb-client php7.3 php-mysql \
                    php-fpm vim wget curl php-xml php-cli php-mbstring
RUN wget https://wordpress.org/latest.tar.gz && \
        tar -xvf latest.tar.gz && \
        mv /wordpress/* /var/www/html/ && \
        chown -R www-data:www-data /var/www/html && \ 
        rm -r /wordpress latest.tar.gz
RUN rm /var/www/html/wp-config-sample.php
COPY /tools/wp-config.php /var/www/html/wp-config.php

RUN rm /etc/php/7.3/fpm/pool.d/www.conf
COPY /conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN service php7.3-fpm start