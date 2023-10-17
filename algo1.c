/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:38:37 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 20:08:20 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	algo_3(t_data *data)
// {

// }

// void	algo_4(t_data *data)
// {

// }

// void	algo_5(t_data *data)
// {

// }

void	algo_big(t_data *data)
{
	t_moves	*move;

	give_lst_pos(data);
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
