# srcs/requirements/nginx/Dockerfile

FROM debian:buster 

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install nginx -y
RUN apt-get install openssl -y
RUN apt-get install vim -y

COPY    conf/nginx.conf /etc/nginx/sites-available/default

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gun/CN=localhost" \
		-out /etc/ssl/certs/yubchoi.42.fr.crt \
		-keyout /etc/ssl/private/yubchoi.42.fr.key

RUN		touch /var/www/html/phpinfo.php

ENTRYPOINT     ["nginx", "-g", "daemon off;"]

EXPOSE 443
