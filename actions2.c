/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:39:47 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/18 01:45:07 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_lst	*last;

	last = ft_lstlast(data->la);
	if (last != NULL && data->la != last)
	{
		last->next = data->la;
		data->la = data->la->next;
		last->next->next = NULL;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_data *data)
{
	t_lst	*last;

	last = ft_lstlast(data->lb);
	if (last != NULL && data->lb != last)
	{
		last->next = data->lb;
		data->lb = data->lb->next;
		last->next->next = NULL;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_data *data)
{
	t_lst	*last_la;
	t_lst	*last_lb;

	last_la = ft_lstlast(data->la);
	last_lb = ft_lstlast(data->lb);
	if (last_la != NULL && data->la != last_la
		&& last_lb != NULL && data->lb != last_lb)
	{
		last_la->next = data->la;
		data->la = data->la->next;
		last_la->next->next = NULL;
		last_lb->next = data->lb;
		data->lb = data->lb->next;
		last_lb->next->next = NULL;
		ft_putstr_fd("rr\n", 1);
	}
}
