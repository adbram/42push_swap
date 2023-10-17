/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:28:58 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/17 18:05:52 by aberramo         ###   ########.fr       */
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
	data->len = ac - 1;
	data->median = data->len / 2;
	push_swap(data);
	ft_lstclear(data->la);
	ft_lstclear(data->lb);
	free(data);
}
