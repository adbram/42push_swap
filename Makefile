# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 19:22:31 by aberramo          #+#    #+#              #
#    Updated: 2023/10/07 22:00:15 by aberramo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEAULT_GOAL	= all
NAME			= push_swap

SRCS			= main.c\
					push_swap.c\
					ft_exit.c\
					check.c\
					lst.c\
					ft_lstnew.c\
					ft_strlen.c\
					ft_putstr_fd.c\
					ft_atoi.c
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