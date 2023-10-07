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

void	parse_la(t_lsts *ls, int ac, char **av)
{
	int	i;

	i = 1;
	(void)ls;
	(void)av;
	while (i < ac)
	{
	}
}

void	init_ls(t_lsts *ls)
{
	ls = (t_lsts *)malloc(sizeof(t_lsts));
	if (!ls)
		ft_exit(ls);
}
