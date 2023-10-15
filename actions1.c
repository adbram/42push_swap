/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:35:18 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/15 04:31:00 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	if (data->la && data->la->next)
	{
		tmp2 = data->la->next;
		data->la->next = data->la->next->next;
		tmp1 = data->la;
		data->la = tmp2;
		data->la->next = tmp1;
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_data *data)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	if (data->lb && data->lb->next)
	{
		tmp2 = data->lb->next;
		data->lb->next = data->lb->next->next;
		tmp1 = data->lb;
		data->lb = tmp2;
		data->lb->next = tmp1;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_data *data)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	if (data->la && data->la->next && data->lb && data->lb->next)
	{
		tmp2 = data->la->next;
		data->la->next = data->la->next->next;
		tmp1 = data->la;
		data->la = tmp2;
		data->la->next = tmp1;
		tmp2 = data->lb->next;
		data->lb->next = data->lb->next->next;
		tmp1 = data->lb;
		data->lb = tmp2;
		data->lb->next = tmp1;
		ft_putstr_fd("ss\n", 1);
	}
}

void	pa(t_data *data)
{
	t_lst	*tmp;

	if (data->lb)
	{
		tmp = data->lb;
		data->lb = data->lb->next;
		tmp->next = data->la;
		data->la = tmp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_data *data)
{
	t_lst	*tmp;

	if (data->la)
	{
		tmp = data->la;
		data->la = data->la->next;
		tmp->next = data->lb;
		data->lb = tmp;
		ft_putstr_fd("pb\n", 1);
	}
}
