# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 17:10:07 by ede-alme          #+#    #+#              #
#    Updated: 2022/06/24 19:59:02 by ede-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

#Flags bellow:
FLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

#Compilator bellow:
CC = gcc

#Sources bellow:
SOURCE_SERVER = ./servers/server.c ./includes/ft_printf.c ./includes/ft_printf_utils.c
SOURCE_CLIENT = ./clients/client.c ./includes/ft_printf.c ./includes/ft_printf_utils.c
SOURCE_SERVER_BONUS = ./servers/server_bonus.c ./includes/ft_printf.c ./includes/ft_printf_utils.c
SOURCE_CLIENT_BONUS = ./clients/client_bonus.c ./includes/ft_printf.c ./includes/ft_printf_utils.c

#Objects bellow:
OBJ_SERVER = $(SOURCE_SERVER:.c=.o)
OBJ_CLIENT = $(SOURCE_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SOURCE_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SOURCE_CLIENT_BONUS:.c=.o)

%.o: %.c
	$(CC) $(SANITIZE) $(FLAGS) -c $< -o $@

#Rule mandatory:
all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

#Mandatory:
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(SANITIZE) -o $@ $(OBJ_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(SANITIZE) -o $@ $(OBJ_CLIENT)

#Bonus:
$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(CC) $(SANITIZE) -o $@ $(OBJ_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(SANITIZE) -o $@ $(OBJ_CLIENT_BONUS)

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@echo "All clear"
	
re: fclean all
	
.PHONY: all clean fclean re bonus