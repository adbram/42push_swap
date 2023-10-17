/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:49:07 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/18 01:44:14 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_splitclear(t_parsed *p)
{
	int	i;

	if (p)
	{
		i = 0;
		while (i < p->size)
		{
			free(p->strs[i]);
			i++;
		}
		free(p->strs);
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
