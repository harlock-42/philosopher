# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 10:45:35 by tallaire          #+#    #+#              #
#    Updated: 2021/10/12 13:55:18 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m


NAME	=	philo

CC	=	clang

RM	=	rm -rf

CP	=	cp -r

CFLAGS	=	-Werror -Wextra -Wall -c -g3

TFLAGS	=	-lpthread

SRC		+=	aie.c
SRC		+=	display_act.c
SRC		+=	ft_atoi.c
SRC		+=	ft_bzero.c
SRC		+=	ft_itoa.c
SRC		+=	ft_putnbr_fd.c
SRC		+=	ft_strcat.c
SRC		+=	ft_strcmp.c
SRC		+=	ft_strdup.c
SRC		+=	ft_strjoin.c
SRC		+=	ft_strlen.c
SRC		+=	ft_usleep.c
SRC		+=	free_env.c
SRC		+=	get_arg.c
SRC		+=	get_time.c
SRC		+=	init.c
SRC		+=	is_uintovf.c
SRC		+=	launch_philo.c
SRC		+=	lst_add_back.c
SRC		+=	lst_add_front.c
SRC		+=	lst_dup.c
SRC		+=	lst_free.c
SRC		+=	lst_free_env.c
SRC		+=	lst_new.c
SRC		+=	lst_print.c
SRC		+=	lst_rm_back.c
SRC		+=	lst_rm_front.c
SRC		+=	lst_rm_next.c
SRC		+=	lst_size.c
SRC		+=	lst_sort_token.c
SRC		+=	lst_to_string.c
SRC		+=	main.c
SRC		+=	where_is_c.c

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/list/
vpath %.c srcs/utils/

OBJ		=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

HEADER_NAME	=	philo.h

LIB_PATH	=	./.lib

HEADER_PATH	=	./include

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(CC) -I$(HEADER_PATH)/ $(TFLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER)
	@$(CC) -I$(HEADER_PATH)/ $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
