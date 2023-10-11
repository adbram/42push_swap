/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:48:55 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/11 15:44:55 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_lst **la, t_lst **lb, int la_len)
{
	int	min_med1;
	int	min_med2;
	int	max_med1;
	int	max_med2;

	(void)lb;
	min_med1 = get_min1_la_mvs(la, la_len);
	min_med2 = get_min2_la_mvs(la, la_len);
	max_med1 = get_max1_la_mvs(la, la_len);
	max_med2 = get_max2_la_mvs(la, la_len);
	printf("min_med1 = %i\n", min_med1);
	printf("max_med1 = %i\n", max_med1);
	printf("min_med2 = %i\n", min_med2);
	printf("max_med2 = %i\n", max_med2);
}
