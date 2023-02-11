/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:00:40 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/11 18:13:48 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	move_plusplus(t_stack **stack_a, t_stack **stack_b, int x, int y)
{
	int	i;

	i = 0;
	while (i < x && i < y)
	{
		rr(stack_a, stack_b);
		i++;
	}
	while (i < x || i < y)
	{
		if (i < x)
			ra(stack_a);
		else if (i < y)
			rb(stack_b);
		i++;
	}
	pa(stack_a, stack_b);
}

void	move_plusminus(t_stack **stack_a, t_stack **stack_b, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ra(stack_a);
		i++;
	}
	while (y < 0)
	{
		rrb(stack_b);
		y++;
	}
	pa(stack_a, stack_b);
}

void	move_minusplus(t_stack **stack_a, t_stack **stack_b, int x, int y)
{
	int	i;

	i = 0;
	while (x < 0)
	{
		rra(stack_a);
		x++;
	}
	while (i < y)
	{
		rb(stack_b);
		i++;
	}
	pa(stack_a, stack_b);
}

void	move_minusminus(t_stack **stack_a, t_stack **stack_b, int x, int y)
{
	int	i;

	i = 0;
	while (x < 0 && y < 0)
	{
		rrr(stack_a, stack_b);
		x++;
		y++;
	}
	while (x < 0 || y < 0)
	{
		if (x < 0)
		{
			rra(stack_a);
			x++;
		}
		else if (y < 0)
		{
			rrb(stack_b);
			y++;
		}
	}
	pa(stack_a, stack_b);
}

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
