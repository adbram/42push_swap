/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:38:37 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 23:50:48 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_data *data)
{
	t_lst	*la1;
	t_lst	*la2;
	t_lst	*la3;

	la1 = data->la;
	la2 = la1->next;
	la3 = la2->next;
	if (la1->val > la2->val && la1->val < la3->val && la2->val < la3->val)
		sa(data);
	else if (la1->val > la2->val && la2->val > la3->val)
	{
		sa(data);
		rra(data);
	}
	else if (la1->val > la2->val && la2->val < la3->val && la1->val > la3->val)
		ra(data);
	else if (la1->val < la2->val && la1->val < la3->val && la2->val > la3->val)
	{
		sa(data);
		ra(data);
	}
	else if (la1->val < la2->val && la1->val > la3->val)
		rra(data);
}

void	algo_5(t_data *data)
{
	pb(data);
	pb(data);
	algo_3(data);
	algo_big(data);
}

void	algo_big(t_data *data)
{
	t_moves	*move;

	clear_la(data);
	if (!data->la)
		pa(data);
	while (data->lb)
	{
		move = calc_next_move(data);
		exec_move(data, move);
		free(move);
	}
	move_top(data, 0);
}
