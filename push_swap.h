/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:30:20 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/15 02:39:49 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_lst
{
	int				value;
	int				pos;
	struct s_lst	*next;
}	t_lst;

void	push_swap(t_lst **la, t_lst **lb, int la_len);
void	check(t_lst **la, t_lst **lb, int ac, char **av);

void	parse_la(t_lst **la, t_lst **lb, int ac, char **av);
void	print_lsts(t_lst **la, t_lst **lb);
void	give_lst_pos(t_lst **la);

void	ft_exit(t_lst **la, t_lst **lb);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(t_lst **la, t_lst **lb, char *nptr);
int		ft_strlen(char *str);

t_lst	*ft_lstnew(t_lst **la, t_lst **lb, int value);
t_lst	*ft_lstlast(t_lst **lst);
t_lst	*ft_lstndlast(t_lst **lst);

void	sa(t_lst **la);
void	sb(t_lst **lb);
void	ss(t_lst **la, t_lst **lb);
void	pa(t_lst **la, t_lst **lb);
void	pb(t_lst **la, t_lst **lb);
void	ra(t_lst **la);
void	rb(t_lst **lb);
void	rr(t_lst **la, t_lst **lb);
void	rra(t_lst **la);
void	rrb(t_lst **lb);
void	rrr(t_lst **la, t_lst **lb);

int		get_min1_la_mvs(t_lst **la, int la_len);
int		get_min2_la_mvs(t_lst **la, int la_len);
int		get_max1_la_mvs(t_lst **la, int la_len);
int		get_max2_la_mvs(t_lst **la, int la_len);

int		get_min_lb_mvs(t_lst **lb, int value);
int		get_max_lb_mvs(t_lst **lb, int value);

#endif
