/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:48:55 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 18:08:05 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_st_value(t_data *data)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = data->la;
	while (i < data->len)
	{
		if (tmp->pos == 0)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < data->median)
	{
		while (i-- > 0)
			ra(data);
	}
	else
	{
		i = data->len - i;
		while (i-- > 0)
			rra(data);
	}
}

static void	clear_la(t_data *data)
{
	while (data->la)
	{
		if (data->la->pos <= data->median)
			pb(data);
		else
		{
			pb(data);
			rb(data);
		}
	}
}

void	push_swap(t_data *data)
{
	t_moves	*move;

	give_lst_pos(data);
	clear_la(data);
	pa(data);
	while (data->lb)
	{
		move = calc_next_move(data);
		exec_move(data, move);
		free(move);
	}
	move_st_value(data);
}
