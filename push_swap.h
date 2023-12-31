/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:30:20 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/21 16:18:53 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_parsed
{
	char	**strs;
	int		size;
}	t_parsed;

typedef struct s_lst
{
	int				val;
	int				pos;
	struct s_lst	*next;
}	t_lst;

typedef struct s_data
{
	t_lst	*la;
	t_lst	*lb;
	int		len;
	int		la_len;
	int		lb_len;
	int		median;
	int		ac;
}	t_data;

typedef struct s_moves
{
	int	total;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	val;
}	t_moves;

void		push_swap(t_data *data);
void		check(t_data *data, char **av);

void		parse_la(t_data *data, char **av);
void		give_lst_pos(t_data *data);
int			*lst_to_tab(t_data *data);

void		ft_exit(t_data *data, int status);
void		ft_putstr_fd(char *str, int fd);
int			ft_atoi(t_data *data, char *nptr);
int			ft_strlen(char *str);
t_parsed	*ft_split(t_data *data, char *str, char *charset);
void		ft_splitclear(t_parsed *p);
int			ft_ischarset(char c, char *charset);

t_lst		*ft_lstnew(t_data *data, int val, int pos);
t_lst		*ft_lstlast(t_lst *lst);
t_lst		*ft_lstndlast(t_lst *lst);
void		ft_lstclear(t_lst *lst);
int			ft_lstlen(t_lst *lst);

void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

void		exec_move(t_data *data, t_moves *move);
t_moves		*calc_next_move(t_data *data);
void		move_top(t_data *data, int pos);
void		moves_cmp(t_moves *curr_moves, t_moves *min_moves);
void		clear_la(t_data *data);
int			is_sorted(t_data *data);

void		algo_3(t_data *data);
void		algo_5(t_data *data);
void		algo_big(t_data *data);

#endif
