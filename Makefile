# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 20:42:34 by ekuchel           #+#    #+#              #
#    Updated: 2023/07/28 19:05:18 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	./src/main.c \
		./src/utils.c \
		./src/utils2.c \
		./src/utils3.c \
		./src/readfile.c \
		./src/draw.c

# tester.c

LIBFT = ./lib/libft/libft.a

LIBMLX = ./lib/minilibx_macos/libmlx.a

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
RM = rm -rf
CC = gcc -g

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(SRC)
	$(CC) $(CFLAGS) -framework OpenGL -framework Appkit -I./lib $(LIBFT) $(LIBMLX) $(SRC) -o $(NAME)

$(LIBFT):
	make -s -C ./lib/libft/

$(LIBMLX):
	make -s -C ./lib/minilibx_macos/

# %.o: %.cc
# 	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./lib/libft/
	make clean -C ./lib/minilibx_macos/

# $(RM) -f $(SRC_OBJ) $(SRC_OBJB)

fclean:
	make fclean -C ./lib/libft/
	$(RM) -f $(NAME)

sclean:
	$(RM) -f $(NAME)

re: sclean all

PHONY : all re clean fclean sclean
