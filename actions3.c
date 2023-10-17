/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:40:09 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 18:24:47 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	t_lst	*ndlast;

	ndlast = ft_lstndlast(data->la);
	if (ndlast != NULL && ndlast->next != NULL)
	{
		ndlast->next->next = data->la;
		data->la = ndlast->next;
		ndlast->next = NULL;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_data *data)
{
	t_lst	*ndlast;

	ndlast = ft_lstndlast(data->lb);
	if (ndlast != NULL && ndlast->next != NULL)
	{
		ndlast->next->next = data->lb;
		data->lb = ndlast->next;
		ndlast->next = NULL;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_data *data)
{
	t_lst	*ndlast_la;
	t_lst	*ndlast_lb;

	ndlast_la = ft_lstndlast(data->la);
	ndlast_lb = ft_lstndlast(data->lb);
	if (ndlast_la != NULL && ndlast_la->next != NULL
		&& ndlast_lb != NULL && ndlast_lb->next != NULL)
	{
		ndlast_la->next->next = data->la;
		data->la = ndlast_la->next;
		ndlast_la->next = NULL;
		ndlast_lb->next->next = data->lb;
		data->lb = ndlast_lb->next;
		ndlast_lb->next = NULL;
		ft_putstr_fd("rrr\n", 1);
	}
}
