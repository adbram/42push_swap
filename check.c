/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:46:30 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/18 01:06:57 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_double_vals(t_data *data)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = data->la;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->val == tmp2->val)
				ft_exit(data, EXIT_FAILURE);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	check(t_data *data, char **av)
{
	if (data->ac == 1)
		ft_exit(data, EXIT_SUCCESS);
	parse_la(data, av);
	if (data->len == 2)
		ft_exit(data, EXIT_SUCCESS);
	check_double_vals(data);
}
