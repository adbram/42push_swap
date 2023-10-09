/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:44:29 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/07 17:48:12 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_la(t_lst **la, t_lst **lb, int ac, char **av)
{
	int		i;
	t_lst	*new;

	i = ac - 1;
	while (i > 0)
	{
		new = ft_lstnew(la, lb, ft_atoi(la, lb, av[i]), i);
		new->next = (*la);
		(*la) = new;
		i--;
	}
}
