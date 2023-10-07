/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:18:59 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/07 22:03:45 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strint_len(char *str)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	len = 0;
	start = 0;
	while (str[i])
	{
		if (start == 0 && str[i] > '0' && str[i] <= '9')
			start = 1;
		if (str[i] != '-' && str[i] != '+' && start == 1)
			len++;
		i++;
	}
	return (len);
}

static int	cmp_strint_overflow(t_lsts *ls, char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = len;
	while (i > len - 10)
}

static int	check_int_overflow(t_lsts *ls, char *str)
{
	int	len;

	(void)ls;
	len = strint_len(str);
	if (len > 10)
		ft_exit(ls);
	if (len == 10)
		cmp_strint_overflow(ls, str);
	return (len);
}

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
		sign *= -1;
	else if (str[*i] == '+')
		sign *= 1;
	if (str[*i] == '-' || str[*i] == '+')
		*i = *i + 1;
	return (sign);
}

int	ft_atoi(t_lsts *ls, char *nptr)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	(void)ls;
	while (nptr[i] != '\0')
	{
		if (nptr[i] != ' ' && nptr[i] != '\f' && nptr[i] != '\n'
			&& nptr[i] != '\r' && nptr[i] != '\t' && nptr[i] != '\v')
			break ;
		i++;
	}
	sign = get_sign(nptr, &i);
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] != '\0')
		ft_exit(ls);
	printf("len = %i\n", check_int_overflow(ls, nptr));
	return (res * sign);
}
