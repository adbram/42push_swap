/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:39:47 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/09 16:44:38 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lst **la)
{
	t_lst	*last;

	last = ft_lstlast(la);
	if (last != NULL && *la != last)
	{
		last->next = *la;
		*la = (*la)->next;
		last->next->next = NULL;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_lst **lb)
{
	t_lst	*last;

	last = ft_lstlast(lb);
	if (last != NULL && *lb != last)
	{
		last->next = *lb;
		*lb = (*lb)->next;
		last->next->next = NULL;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_lst **la, t_lst **lb)
{
	t_lst	*last_la;
	t_lst	*last_lb;

	last_la = ft_lstlast(la);
	last_lb = ft_lstlast(lb);
	if (last_la != NULL && *la != last_la && last_lb != NULL && *lb != last_lb)
	{
		last_la->next = *la;
		*la = (*la)->next;
		last_la->next->next = NULL;
		last_lb->next = *lb;
		*lb = (*lb)->next;
		last_lb->next->next = NULL;
		ft_putstr_fd("rr\n", 1);
	}
}
