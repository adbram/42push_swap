/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:48:55 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/16 21:19:26 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_move(t_data *data, t_moves *move)
{
	if (move->rb != 0)
		while (move->rb-- > 0)
			rb(data);
	else if (move->rrb != 0)
		while (move->rrb-- > 0)
			rrb(data);
	if (move->ra != 0)
		while (move->ra-- > 0)
			ra(data);
	else if (move->rra != 0)
		while (move->rra-- > 0)
			rra(data);
	pa(data);
}

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
	}
	move_st_value(data);
}
	// printf("curr_moves->ra = %i\n", curr_moves->ra);
	// printf("curr_moves->rra = %i\n", curr_moves->rra);
	// printf("curr_moves->rb = %i\n", curr_moves->rb);
	// printf("curr_moves->rrb = %i\n", curr_moves->rrb);
	// printf("curr_moves->value = %i\n", curr_moves->value);
	// printf("curr_moves->total = %i\n\n", curr_moves->total);

	// printf("min_moves->ra = %i\n", min_moves->ra);
	// printf("min_moves->rra = %i\n", min_moves->rra);
	// printf("min_moves->rb = %i\n", min_moves->rb);
	// printf("min_moves->rrb = %i\n", min_moves->rrb);
	// printf("min_moves->value = %i\n", min_moves->value);
	// printf("min_moves->total = %i\n\n", min_moves->total);
