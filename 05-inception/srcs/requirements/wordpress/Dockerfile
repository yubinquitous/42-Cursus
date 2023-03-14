## srcs/requirements/wordpress/Dockerfile

FROM	debian:buster

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get -y install \
		mariadb-client \
		php-mysql \
		php-mbstring \
		wget \
		tar \
		php7.3-fpm \
		vim

RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvzf latest.tar.gz
RUN		mkdir -p /var/www/html/wordpress
RUN		mv wordpress/ /var/www/html/

COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN		chown -R www-data:www-data /var/www/html/wordpress

EXPOSE	9000

CMD		service php7.3-fpm start && tail -f /dev/null