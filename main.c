/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/15 04:37:44 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_exit(data);
	data->la = NULL;
	data->lb = NULL;
	check(data, ac, av);
	print_lsts(data);
	data->la_len = ac - 1;
	push_swap(data);
	print_lsts(data);
}
