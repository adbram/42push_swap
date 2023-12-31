/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:07:46 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 23:40:22 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*init_moves(t_data *data)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		ft_exit(data, EXIT_FAILURE);
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->total = -1;
	moves->val = 0;
	return (moves);
}

static void	calc_la_moves2(t_data *data, t_moves *moves, t_lst *sup, t_lst *min)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = data->la;
	while (i < data->la_len)
	{
		if (min->pos < 0 || min->val > tmp->val)
		{
			min->val = tmp->val;
			min->pos = i;
		}
		if (moves->val < tmp->val && (sup->pos < 0
				|| sup->val > tmp->val))
		{
			sup->val = tmp->val;
			sup->pos = i;
		}
		tmp = tmp->next;
		i++;
	}
}

static void	calc_la_moves(t_data *data, t_moves *moves)
{
	t_lst	*min;
	t_lst	*sup;

	min = ft_lstnew(data, 0, -1);
	sup = ft_lstnew(data, 0, -1);
	calc_la_moves2(data, moves, sup, min);
	if (sup->pos >= 0)
	{
		if ((data->la_len == 3 && sup->pos <= 1)
			|| (sup->pos < data->la_len / 2))
			moves->ra += sup->pos;
		else
			moves->rra += data->la_len - sup->pos;
		free(sup);
		free(min);
		return ;
	}
	if ((data->la_len == 3 && min->pos <= 1) || (min->pos < data->la_len / 2))
		moves->ra += min->pos;
	else if (data->la_len > 1)
		moves->rra += data->la_len - min->pos;
	free(sup);
	free(min);
}

static void	calc_next_move2(t_data *data, t_moves *c_m, t_moves *m_m, int i)
{
	if (i < data->lb_len / 2)
		c_m->rb += i;
	else
		c_m->rrb += data->lb_len - i;
	if (data->la_len > 0)
		calc_la_moves(data, c_m);
	c_m->total = c_m->ra + c_m->rb
		+ c_m->rra + c_m->rrb;
	moves_cmp(c_m, m_m);
}

t_moves	*calc_next_move(t_data *data)
{
	int		i;
	t_lst	*tmp;
	t_moves	*curr_moves;
	t_moves	*min_moves;

	data->la_len = ft_lstlen(data->la);
	data->lb_len = ft_lstlen(data->lb);
	i = 0;
	tmp = data->lb;
	curr_moves = init_moves(data);
	min_moves = init_moves(data);
	while (i < data->lb_len)
	{
		curr_moves->val = tmp->val;
		calc_next_move2(data, curr_moves, min_moves, i);
		tmp = tmp->next;
		i++;
	}
	free(curr_moves);
	return (min_moves);
}
