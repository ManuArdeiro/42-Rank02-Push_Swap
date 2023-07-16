# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 18:15:39 by jolopez-          #+#    #+#              #
#    Updated: 2023/04/08 10:10:41 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

SRCS 		= ./srcs/push_swap.c \
			./srcs/push_swap_aux.c \
			./srcs/radix.c \
			./srcs/five_elements.c \
			./srcs/tools/atoi.c \
			./srcs/tools/n_root.c \
			./srcs/tools/split.c \
			./srcs/tools/stack_tools_1.c \
			./srcs/tools/stack_tools_2.c \
			./srcs/tools/tools.c \
			./srcs/movements/push_movs.c \
			./srcs/movements/reverse_rotate_movs.c \
			./srcs/movements/rotate_movs.c \
			./srcs/movements/swap_movs.c

OBJS		= $(SRCS:.c=.o)

INC 		= -I includes

LIBS		= 

CC = 		gcc

CFLAGS 		= -Wall -Werror -Wextra $(INC) -g3

RM			= rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW) Creating push_swap... $(WHITE)"
			${CC} $(CFLAGS) -o ${NAME} ${OBJS} $(LIBS)
			@echo "$(GREEN) Done..."	

clean:		
			@echo "$(LIGHT_RED) Cleaning objects... $(WHITE)"
			$(RM) $(OBJS)

fclean: 	clean
			@echo "$(LIGHT_RED) Cleaning all... $(WHITE)"
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re

# COLORS
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
LIGHT_GRAY	= \033[0;37m
DARK_GRAY	= \033[0;90m
LIGHT_RED	= \033[0;91m
WHITE		= \033[0;97m

#SETS
BOLD		= \e[0;1m
UNDERLINED	= \e[0;4m
BLINK		= \e[0;5m
