/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:49:07 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/07 18:10:55 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstclear(t_lst *lst)
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

void	ft_exit(t_lsts *ls)
{
	ft_putstr_fd("Error\n", 2);
	if (ls)
	{
		ft_lstclear(ls->la);
		ft_lstclear(ls->lb);
		free(ls);
	}
	exit(EXIT_FAILURE);
}
