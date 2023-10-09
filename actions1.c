/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:35:18 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/09 16:45:03 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst **la)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	if (*la && (*la)->next)
	{
		tmp2 = (*la)->next;
		(*la)->next = (*la)->next->next;
		tmp1 = (*la);
		(*la) = tmp2;
		(*la)->next = tmp1;
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_lst **lb)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	if (*lb && (*lb)->next)
	{
		tmp2 = (*lb)->next;
		(*lb)->next = (*lb)->next->next;
		tmp1 = (*lb);
		(*lb) = tmp2;
		(*lb)->next = tmp1;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_lst **la, t_lst **lb)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	if (*la && (*la)->next && *lb && (*lb)->next)
	{
		tmp2 = (*la)->next;
		(*la)->next = (*la)->next->next;
		tmp1 = (*la);
		(*la) = tmp2;
		(*la)->next = tmp1;
		tmp2 = (*lb)->next;
		(*lb)->next = (*lb)->next->next;
		tmp1 = (*lb);
		(*lb) = tmp2;
		(*lb)->next = tmp1;
		ft_putstr_fd("ss\n", 1);
	}
}

void	pa(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;

	if (*lb)
	{
		tmp = *lb;
		*lb = (*lb)->next;
		tmp->next = (*la);
		(*la) = tmp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;

	if (*la)
	{
		tmp = *la;
		*la = (*la)->next;
		tmp->next = (*lb);
		(*lb) = tmp;
		ft_putstr_fd("pb\n", 1);
	}
}
