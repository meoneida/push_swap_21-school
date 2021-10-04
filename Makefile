# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 01:09:41 by meoneida          #+#    #+#              #
#    Updated: 2021/09/23 01:25:59 by meoneida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= push_swap.c parsing.c prepare.c\
			  algorithm.c actions.c utils.c free_mem.c

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc

FLAGS		= -Wall -Wextra -Werror 

HEADER 		= push_swap.h

.PHONY: 	all clean fclean re

%.o:%.c		${HEADER}
			@${CC} ${FLAGC} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER)
			${CC} ${FLAGS} -o ${NAME} $(OBJS)

all:		$(NAME)
		
clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			
re:			fclean all
