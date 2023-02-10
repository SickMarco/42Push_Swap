/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/09 20:24:51 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_mover(t_stack **stack_a, t_stack **stack_b, t_bigsort **bs)
{
	int	x;
	int	y;

	x = (*bs)->a->arr[(*bs)->best->pos];
	y = (*bs)->b->arr[(*bs)->best->pos];
	if (*stack_b)
	{
		if (x >= 0 && y >= 0)
			move_plusplus(stack_a, stack_b, x, y);
		else if (x >= 0 && y <= 0)
			move_plusminus(stack_a, stack_b, x, y);
		else if (x <= 0 && y >= 0)
			move_minusplus(stack_a, stack_b, x, y);
		else if (x <= 0 && y <= 0)
			move_minusminus(stack_a, stack_b, x, y);
	}
	free((*bs)->a->arr);
	free((*bs)->b->arr);
}

void	ft_selector2(t_move **a, t_move **b, t_selector **sel, int i)
{
	if ((*a)->arr[i] <= 0 && (*b)->arr[i] >= 0)
	{
		if (ft_abs((*a)->arr[i]) + (*b)->arr[i] < (*sel)->best)
		{
			(*sel)->best = ft_abs((*a)->arr[i]) + (*b)->arr[i];
			(*sel)->pos = i;
		}
	}
	else if ((*a)->arr[i] <= 0 && (*b)->arr[i] <= 0)
	{
		if ((*a)->arr[i] > (*b)->arr[i] && ft_abs((*b)->arr[i]) < (*sel)->best)
		{
			(*sel)->best = ft_abs((*b)->arr[i]);
			(*sel)->pos = i;
		}
		else if ((*a)->arr[i] < (*b)->arr[i]
			&& ft_abs((*a)->arr[i]) < (*sel)->best)
		{
			(*sel)->best = ft_abs((*a)->arr[i]);
			(*sel)->pos = i;
		}
	}
}

void	ft_selector1(t_move **a, t_move **b, t_selector **sel, int i)
{
	if ((*a)->arr[i] >= 0 && (*b)->arr[i] >= 0)
	{
		if ((*a)->arr[i] > (*b)->arr[i] && (*a)->arr[i] < (*sel)->best)
		{
			(*sel)->best = (*a)->arr[i];
			(*sel)->pos = i;
		}
		else if ((*a)->arr[i] < (*b)->arr[i] && (*b)->arr[i] < (*sel)->best)
		{
			(*sel)->best = (*b)->arr[i];
			(*sel)->pos = i;
		}
	}
	else if ((*a)->arr[i] >= 0 && (*b)->arr[i] <= 0)
	{
		if ((*a)->arr[i] + ft_abs((*b)->arr[i]) < (*sel)->best)
		{
			(*sel)->best = (*a)->arr[i] + ft_abs((*b)->arr[i]);
			(*sel)->pos = i;
		}
	}
}

void	ft_selector(t_move **a, t_move **b, t_selector **sel, int len)
{
	int	i;

	i = 0;
	(*sel)->best = INT_MAX;
	(*sel)->pos = 0;
	while (i < len)
	{
		if ((*sel)->best == 1 && (*sel)->pos == 0)
			break ;
		ft_selector1(a, b, sel, i);
		ft_selector2(a, b, sel, i);
		i++;
	}
}
