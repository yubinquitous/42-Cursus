NAME = inception

VOLUME_PATH		:= /home/yubchoi/data
HOST_LINK	:= "127.0.0.1	yubchoi.42.fr" > /etc/hosts

all		:	$(NAME)
.PHONY	: all

$(NAME)	:
	@sudo mkdir -p $(VOLUME_PATH)/mariadb/
	@sudo mkdir -p $(VOLUME_PATH)/wordpress/
	@sudo echo $(HOST_LINK)
	@sudo docker-compose -f ./srcs/docker-compose.yml up --build -d

up		:
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d
.PHONY	: up

down	:
	@sudo docker-compose -f ./srcs/docker-compose.yml down
.PHONY	: down

clean	:
	@sudo docker-compose -f ./srcs/docker-compose.yml down --rmi all --volumes
.PHONY	: clean

fclean	: clean
	@sudo rm -rf $(VOLUME_PATH)
.PHONY	: fclean

re	:
	$(MAKE) fclean
	$(MAKE) all

.PHONY	: re