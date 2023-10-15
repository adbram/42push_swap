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

int	*lst_to_tab(t_lst **lst)
{
	int		*tab;
	int		len;
	t_lst	*tmp;
	int		i;

	len = ft_lstlen(lst);
	tab = (int *)malloc(sizeof(int) * len + 1);
	if (!tab)
		ft_exit(lst, (t_lst **)NULL);
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	sort_tab(int **tab)
{
	int	i;
	int	sorted;
	int	tmp;

	sorted = 0;
	while (sorted == 0)
	{
		i = 0;
		sorted = 1;
		while ((*tab)[i])
		{
			if ((*tab)[i + 1] && (*tab)[i] > (*tab)[i + 1])
			{
				tmp = (*tab)[i];
				(*tab)[i] = (*tab)[i + 1];
				(*tab)[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	give_lst_pos(t_lst **la)
{
	int		*tab;
	int		i;
	t_lst	*tmp;

	tab = lst_to_tab(la);
	sort_tab(&tab);
	tmp = *la;
	while (tmp)
	{
		i = 0;
		while (tab[i])
		{
			if (tab[i] == tmp->value)
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

void	print_lsts(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;

	if (la)
	{
		tmp = *la;
		while (tmp)
		{
			printf("la->value = %i, la->pos = %i\n", tmp->value, tmp->pos);
			tmp = tmp->next;
		}
	}
	printf("\n");
	if (lb)
	{
		tmp = *lb;
		while (tmp)
		{
			printf("lb->value = %i, lb->pos = %i\n", tmp->value, tmp->pos);
			tmp = tmp->next;
		}
	}
}

void	parse_la(t_lst **la, t_lst **lb, int ac, char **av)
{
	int		i;
	t_lst	*new;

	i = ac - 1;
	while (i > 0)
	{
		new = ft_lstnew(la, lb, ft_atoi(la, lb, av[i]));
		new->next = (*la);
		(*la) = new;
		i--;
	}
}


// i = 0;
// while (tab[i])
// {
// 	printf("\"%i\"\n", tab[i]);
// 	i++;
// }