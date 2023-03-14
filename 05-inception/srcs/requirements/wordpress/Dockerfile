# srcs/requirements/wordpress/Dockerfile

FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install php-fpm -y
RUN apt-get install vim -y

COPY	conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN		mkdir -p /var/www/html
COPY	./tmp/phpinfo.php /var/www/html/phpinfo.php

EXPOSE	9000

CMD		service php7.3-fpm start && tail -f /dev/null
