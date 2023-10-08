/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:46:30 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/08 23:37:25 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_lst *la, t_lst *lb, int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_SUCCESS);
	parse_la(la, lb, ac, av);
}
