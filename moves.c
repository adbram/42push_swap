/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:07:46 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/16 21:23:33 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*init_moves(t_data *data)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		ft_exit(data);
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->total = -1;
	moves->value = 0;
	return (moves);
}

static void	calc_la_moves(t_data *data, t_moves *moves)
{
	int		i;
	t_lst	*tmp;
	t_lst	*min;
	t_lst	*sup;

	i = 0;
	tmp = data->la;
	min = ft_lstnew(data, 0, -1);
	sup = ft_lstnew(data, 0, -1);
	while (i < data->la_len)
	{
		if (min->pos < 0 || min->value > tmp->value)
		{
			min->value = tmp->value;
			min->pos = i;
		}
		if (moves->value < tmp->value && (sup->pos < 0
				|| sup->value > tmp->value))
		{
			sup->value = tmp->value;
			sup->pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (sup->pos >= 0)
	{
		if (sup->pos < data->la_len / 2)
			moves->ra += sup->pos;
		else
			moves->rra += data->la_len - sup->pos;
		return ;
	}
	if (min->pos < data->la_len / 2)
		moves->ra += min->pos;
	else if (data->la_len > 1)
		moves->rra += data->la_len - min->pos;
}

static void	moves_cmp(t_moves *curr_moves, t_moves *min_moves)
{
	if (min_moves->total < 0 || min_moves->total > curr_moves->total)
	{
		min_moves->ra = curr_moves->ra;
		min_moves->rb = curr_moves->rb;
		min_moves->rra = curr_moves->rra;
		min_moves->rrb = curr_moves->rrb;
		min_moves->total = curr_moves->total;
		min_moves->value = curr_moves->value;
	}
	curr_moves->ra = 0;
	curr_moves->rb = 0;
	curr_moves->rra = 0;
	curr_moves->rrb = 0;
	curr_moves->total = -1;
	curr_moves->value = 0;
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
		curr_moves->value = tmp->value;
		calc_next_move2(data, curr_moves, min_moves, i);
		tmp = tmp->next;
		i++;
	}
	free(curr_moves);
	return (min_moves);
}
