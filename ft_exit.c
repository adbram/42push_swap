/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:49:07 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/16 20:07:56 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_exit(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(data->la);
	ft_lstclear(data->lb);
	exit(EXIT_FAILURE);
}
