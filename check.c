/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:46:30 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/07 18:16:53 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_lsts *ls, int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_SUCCESS);
	printf("ac = %i, av[0] = %s\n", ac, av[0]);
	parse_la(ls, ac, av);
}
