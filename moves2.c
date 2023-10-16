/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:32:54 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/16 21:33:36 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_cmp(t_moves *curr_moves, t_moves *min_moves)
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
