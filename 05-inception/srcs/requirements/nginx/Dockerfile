# srcs/requirements/nginx/Dockerfile

FROM	debian:buster

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get -y install \
		nginx \
		openssl \
		vim

RUN		mkdir /etc/nginx/ssl

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gun/CN=localhost" \
		-out /etc/ssl/certs/yubchoi.42.fr.crt \
		-keyout /etc/ssl/private/yubchoi.42.fr.key

COPY    conf/nginx.conf /etc/nginx/sites-available/default

EXPOSE	443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
