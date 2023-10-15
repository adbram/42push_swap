/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:48:55 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/15 04:45:25 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	give_lst_pos(data);
	clear_la(data);
}
