# srcs/requirements/wordpress/Dockerfile

FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install php-fpm -y
RUN apt-get install vim -y
RUN apt-get install wget -y
RUN apt-get install tar -y

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz
RUN mkdir -p /var/www/html/wordpress
RUN mv wordpress/ /var/www/html/

COPY	conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

EXPOSE	9000

CMD		service php7.3-fpm start && tail -f /dev/null
