/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:40:09 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/09 18:38:15 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lst **la)
{
	t_lst	*ndlast;

	ndlast = ft_lstndlast(la);
	if (ndlast != NULL && ndlast->next != NULL)
	{
		ndlast->next->next = *la;
		*la = ndlast->next;
		ndlast->next = NULL;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_lst **lb)
{
	t_lst	*ndlast;

	ndlast = ft_lstndlast(lb);
	if (ndlast != NULL && ndlast->next != NULL)
	{
		ndlast->next->next = *lb;
		*lb = ndlast->next;
		ndlast->next = NULL;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_lst **la, t_lst **lb)
{
	t_lst	*ndlast_la;
	t_lst	*ndlast_lb;

	ndlast_la = ft_lstndlast(la);
	ndlast_lb = ft_lstndlast(lb);
	if (ndlast_la != NULL && ndlast_la->next != NULL
		&& ndlast_lb != NULL && ndlast_lb->next != NULL)
	{
		ndlast_la->next->next = *la;
		*la = ndlast_la->next;
		ndlast_la->next = NULL;
		ndlast_lb->next->next = *lb;
		*lb = ndlast_lb->next;
		ndlast_lb->next = NULL;
		ft_putstr_fd("rrr\n", 1);
	}
}
