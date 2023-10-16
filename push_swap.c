/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberramo <aberramo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:48:55 by aberramo          #+#    #+#             */
/*   Updated: 2023/10/16 20:39:55 by aberramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves	*init_moves(t_data *data)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		ft_exit(data);
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->total = -1;
	moves->value = 0;
	return (moves);
}

static void	calc_la_moves(t_data *data, t_moves *moves)
{
	int		i;
	t_lst	*tmp;
	int		min;
	int		min_index;
	int		sup;
	int		sup_index;

	i = 0;
	tmp = data->la;
	min_index = -1;
	sup_index = -1;
	while (i < data->la_len)
	{
		if (min_index < 0 || min > tmp->value)
		{
			min = tmp->value;
			min_index = i;
		}
		if (moves->value < tmp->value && (sup_index < 0 || sup > tmp->value))
		{
			sup = tmp->value;
			sup_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (sup_index >= 0)
	{
		if (sup_index < data->la_len / 2)
			moves->ra += sup_index;
		else
			moves->rra += data->la_len - sup_index;
		return ;
	}
	if (min_index < data->la_len / 2)
		moves->ra += min_index;
	else if (data->la_len > 1)
		moves->rra += data->la_len - min_index;
}

static void	moves_cmp(t_moves *curr_moves, t_moves *min_moves)
{
	if (min_moves->total < 0 || min_moves->total > curr_moves->total)
	{
		min_moves->ra = curr_moves->ra;
		min_moves->rb = curr_moves->rb;
		min_moves->rra = curr_moves->rra;
		min_moves->rrb = curr_moves->rrb;
		min_moves->total = curr_moves->total;
		min_moves->value = curr_moves->value;
	}
	curr_moves->ra = 0;
	curr_moves->rb = 0;
	curr_moves->rra = 0;
	curr_moves->rrb = 0;
	curr_moves->total = -1;
	curr_moves->value = 0;
}

static t_moves	*calc_next_move(t_data *data)
{
	int		i;
	t_lst	*tmp;
	t_moves	*curr_moves;
	t_moves	*min_moves;

	data->la_len = ft_lstlen(data->la);
	data->lb_len = ft_lstlen(data->lb);
	i = 0;
	tmp = data->lb;
	curr_moves = init_moves(data);
	min_moves = init_moves(data);
	while (i < data->lb_len)
	{
		curr_moves->value = tmp->value;
		if (i < data->lb_len / 2)
			curr_moves->rb += i;
		else
			curr_moves->rrb += data->lb_len - i;
		if (data->la_len > 0)
			calc_la_moves(data, curr_moves);
		curr_moves->total = curr_moves->ra + curr_moves->rb +
			curr_moves->rra + curr_moves->rrb;
		// printf("curr_moves->ra = %i\n", curr_moves->ra);
		// printf("curr_moves->rra = %i\n", curr_moves->rra);
		// printf("curr_moves->rb = %i\n", curr_moves->rb);
		// printf("curr_moves->rrb = %i\n", curr_moves->rrb);
		// printf("curr_moves->value = %i\n", curr_moves->value);
		// printf("curr_moves->total = %i\n\n", curr_moves->total);
		moves_cmp(curr_moves, min_moves);
		tmp = tmp->next;
		i++;
	}
	// printf("min_moves->ra = %i\n", min_moves->ra);
	// printf("min_moves->rra = %i\n", min_moves->rra);
	// printf("min_moves->rb = %i\n", min_moves->rb);
	// printf("min_moves->rrb = %i\n", min_moves->rrb);
	// printf("min_moves->value = %i\n", min_moves->value);
	// printf("min_moves->total = %i\n\n", min_moves->total);
	free(curr_moves);
	return (min_moves);
}

static void	exec_move(t_data *data, t_moves *move)
{
	if (move->rb != 0)
	{
		while (move->rb > 0)
		{
			rb(data);
			move->rb--;
		}
	}
	else if (move->rrb != 0)
	{
		while (move->rrb > 0)
		{
			rrb(data);
			move->rrb--;
		}
	}
	if (move->ra != 0)
	{

		while (move->ra > 0)
		{
			ra(data);
			move->ra--;
		}
	}
	else if (move->rra != 0)
	{
		while (move->rra > 0)
		{
			rra(data);
			move->rra--;
		}
	}
	pa(data);
}

void	move_st_value(t_data *data)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = data->la;
	while (i < data->len)
	{
		if (tmp->pos == 0)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < data->median)
	{
		while (i > 0)
		{
			ra(data);
			i--;
		}
	}
	else
	{
		i = data->len - i;
		while (i > 0)
		{
			rra(data);
			i--;
		}
	}
}

static void	clear_la(t_data *data)
{
	while (data->la)
	{
		if (data->la->pos <= data->median)
			pb(data);
		else
		{
			pb(data);
			rb(data);
		}
		
	}
}

void	push_swap(t_data *data)
{
	t_moves	*move;
	give_lst_pos(data);
	clear_la(data);
	pa(data);
	// print_lsts(data);
	while (data->lb)
	{
		move = calc_next_move(data);
		exec_move(data, move);
	}
	move_st_value(data);
}
