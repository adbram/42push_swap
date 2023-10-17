/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:44:29 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/07 17:48:12 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	t_lst	*tmp;

	tmp = data->la;
	while (tmp)
	{
		if (tmp->next && tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	*lst_to_tab(t_data *data)
{
	int		*tab;
	t_lst	*tmp;
	int		i;

	tab = (int *)malloc(sizeof(int) * data->len);
	if (!tab)
		ft_exit(data, EXIT_FAILURE);
	i = 0;
	tmp = data->la;
	while (tmp)
	{
		tab[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

static void	sort_tab(t_data *data, int *tab)
{
	int	i;
	int	sorted;
	int	tmp;

	sorted = 0;
	while (sorted == 0)
	{
		i = 0;
		sorted = 1;
		while (i < data->len)
		{
			if (i + 1 < data->len && tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	give_lst_pos(t_data *data)
{
	int		*tab;
	int		i;
	t_lst	*tmp;

	tab = lst_to_tab(data);
	sort_tab(data, tab);
	tmp = data->la;
	while (tmp)
	{
		i = 0;
		while (tab[i])
		{
			if (tab[i] == tmp->val)
			{
				tmp->pos = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
}

void	parse_la(t_data *data, int ac, char **av)
{
	int		i;
	t_lst	*new;

	i = ac - 1;
	while (i > 0)
	{
		new = ft_lstnew(data, ft_atoi(data, av[i]), 0);
		new->next = data->la;
		data->la = new;
		i--;
	}
}
