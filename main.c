/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/09 19:27:05 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_lst	*la;
	t_lst	*lb;

	la = NULL;
	lb = NULL;
	check(&la, &lb, ac, av);
	// push_swap(&la, &lb, ac - 1);
}
