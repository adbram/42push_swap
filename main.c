/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/18 00:56:44 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_exit(data, EXIT_FAILURE);
	data->la = NULL;
	data->lb = NULL;
	data->ac = ac;
	data->len = 0;
	check(data, av);
	data->median = data->len / 2;
	push_swap(data);
	ft_exit(data, EXIT_SUCCESS);
}
