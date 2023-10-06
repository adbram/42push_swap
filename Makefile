# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 19:22:31 by aberramo          #+#    #+#              #
#    Updated: 2023/10/06 19:52:58 by aberramo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEAULT_GOAL	= all
NAME			= push_swap

SRCS			= main.c\
					push_swap.c\
					check.c
OBJS			= $(SRCS:%.c=%.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3
RM				= rm
RMFLAGS			= -f

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re