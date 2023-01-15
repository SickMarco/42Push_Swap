/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:20:51 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/15 16:40:35 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*stack_a) && (*stack_a)->next != NULL)
	{
		tmp1 = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		tmp2 = (*stack_a)->next;
		(*stack_a)->next = tmp1;
		tmp1->next = tmp2;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*stack_b) && (*stack_b)->next != NULL)
	{
		tmp1 = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		tmp2 = (*stack_b)->next;
		(*stack_b)->next = tmp1;
		tmp1->next = tmp2;
		ft_printf("sb\n");
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_a)
	{
		if (!(*stack_b))
		{
			ft_lstadd_backnum(stack_b, (*stack_a));
			(*stack_a) = (*stack_a)->next;
			(*stack_b)->next = NULL;
		}
		else
		{
			tmp = (*stack_a)->next;
			ft_lstadd_frontnum(stack_b, (*stack_a));
			(*stack_a) = tmp;
		}
		ft_printf("pb\n");
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_b)
	{
		if (!(*stack_a))
		{
			ft_lstadd_backnum(stack_a, (*stack_b));
			(*stack_b) = (*stack_b)->next;
			(*stack_a)->next = NULL;
		}
		else
		{
			tmp = (*stack_b)->next;
			ft_lstadd_frontnum(stack_a, (*stack_b));
			(*stack_b) = tmp;
		}
		ft_printf("pa\n");
	}
}
