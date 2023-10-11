/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:24:19 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/11 16:40:53 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min1_la_mvs(t_lst **la, int la_len)
{
	int		i;
	int		min;
	int		min_index;
	t_lst	*tmp;

	i = 0;
	tmp = *la;
	min = tmp->value;
	min_index = i;
	while (i < la_len / 2)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

int	get_min2_la_mvs(t_lst **la, int la_len)
{
	int		i;
	int		min;
	int		min_index;
	t_lst	*tmp;

	i = 0;
	tmp = *la;
	while (i < la_len / 2)
	{
		tmp = tmp->next;
		i++;
	}
	min = tmp->value;
	min_index = i;
	while (i < la_len)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (la_len - min_index);
}

int	get_max1_la_mvs(t_lst **la, int la_len)
{
	int		i;
	int		max;
	int		max_index;
	t_lst	*tmp;

	i = 0;
	tmp = *la;
	max = tmp->value;
	max_index = i;
	while (i < la_len / 2)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_index);
}

int	get_max2_la_mvs(t_lst **la, int la_len)
{
	int		i;
	int		max;
	int		max_index;
	t_lst	*tmp;

	i = 0;
	tmp = *la;
	while (i < la_len / 2)
	{
		tmp = tmp->next;
		i++;
	}
	max = tmp->value;
	max_index = i;
	while (i < la_len)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (la_len - max_index);
}
