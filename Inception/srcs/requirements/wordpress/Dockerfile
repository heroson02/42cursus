FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y 
RUN apt-get -y install mariadb-client php7.3 php-mysql \
                    php-fpm vim wget curl php-xml php-cli php-mbstring
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvf latest.tar.gz && \
    mkdir /var/www && \
    mv /wordpress/ /var/www/wordpress && \
    chown -R www-data:www-data /var/www/wordpress && \
    rm -r latest.tar.gz
RUN rm /var/www/wordpress/wp-config-sample.php
COPY /tools/wp-config.php /var/www/wordpress/wp-config.php

RUN rm /etc/php/7.3/fpm/pool.d/www.conf
COPY /conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN mkdir /run/php

CMD ./usr/sbin/php-fpm7.3 --nodaemonize