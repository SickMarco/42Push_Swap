/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:35:04 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/12 18:50:29 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	do_sa(t_stack **stack_a)
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
	}
}

void	do_sb(t_stack **stack_b)
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
	}
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
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
	}
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
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
	}
}
