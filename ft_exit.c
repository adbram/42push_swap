/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:49:07 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/18 01:26:42 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_splitclear(t_parsed *p)
{
	if (p)
	{
		while (p->size > 0)
		{
			free(p->strs[p->size]);
			p->size--;
		}
		free(p);
	}
}

void	ft_lstclear(t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ft_exit(t_data *data, int status)
{
	if (status == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	if (data)
	{
		ft_lstclear(data->la);
		ft_lstclear(data->lb);
		free(data);
	}
	exit(status);
}
