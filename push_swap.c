/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:48:55 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 21:00:45 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_data *data, int pos)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = data->la;
	while (i < data->len)
	{
		if (tmp->pos == pos)
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

void	clear_la(t_data *data)
{
	while (data->la)
	{
		if (is_sorted(data) == 1)
			return ;
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
	if (is_sorted(data) == 1)
		ft_exit(data, EXIT_SUCCESS);
	give_lst_pos(data);
	if (data->len == 2)
		sa(data);
	else if (data->len == 3)
		algo_3(data);
	else if (data->len == 5)
		algo_5(data);
	else
		algo_big(data);
}
