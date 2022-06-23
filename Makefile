# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 17:10:07 by ede-alme          #+#    #+#              #
#    Updated: 2022/06/21 09:27:10 by ede-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of executables bellow:
NAME_SERVER = server
NAME_CLIENT = client

#Flags bellow:
FLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

#Compilator bellow:
CC = gcc

#Sources bellow:
SOURCE_SERVER = ./servers/server.c
SOURCE_CLIENT = ./clients/client.c
#SOURCE_INCLUD = ./includes/

#Objects bellow:
OBJ_SERVER = $(SOURCE_SERVER:.c=.o)
OBJ_CLIENT = $(SOURCE_CLIENT:.c=.o)
#OBJ_INCLUD = $(SOURCE_INCLUD:.c=.o)

%.o: %.c
	$(CC) $(SANITIZE) $(FLAGS) -c $< -o $@

#Rule mandatory:
all: $(NAME_SERVER) $(NAME_CLIENT)

#Mandatory:
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(SANITIZE) -o $@ $(OBJ_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(SANITIZE) -o $@ $(OBJ_CLIENT)

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@echo "All clear"
	
re: fclean all
	
.PHONY: all clean fclean re bonus