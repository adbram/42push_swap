/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:46:30 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/09 15:28:15 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_double_values(t_lst **la, t_lst **lb)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = *la;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				ft_exit(la, lb);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	check(t_lst **la, t_lst **lb, int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_SUCCESS);
	parse_la(la, lb, ac, av);
	if (ac == 2)
		exit(EXIT_SUCCESS);
	check_double_values(la, lb);
}
