/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstndlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:17 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/15 04:36:14 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstndlast(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->next->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp)
		return (tmp);
	return (NULL);
}
