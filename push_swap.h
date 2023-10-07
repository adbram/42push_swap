/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:30:20 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/07 21:59:30 by aberramo         ###   ########.fr       */
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
	int				index;
	struct s_lst	*next;
}	t_lst;

typedef struct s_lsts
{
	t_lst	*la;
	t_lst	*lb;
}	t_lsts;

void	push_swap(char *lst);
void	check(t_lsts *ls, int ac, char **av);

void	init_ls(t_lsts *ls);
void	parse_la(t_lsts *ls, int ac, char **av);

void	ft_exit(t_lsts *ls);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(t_lsts *ls, char *nptr);
int		ft_strlen(char *str);

t_lst	*ft_lstnew(t_lsts *ls, int value, int index);

#endif
