/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:00:40 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/08 18:52:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
