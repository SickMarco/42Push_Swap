/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move2_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:36:37 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/12 17:03:22 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	do_ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next != NULL)
	{
		tmp = (*stack_a)->next;
		ft_lstadd_backnum(stack_a, (*stack_a));
		(*stack_a) = tmp;
	}
}

void	do_rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next != NULL)
	{
		tmp = (*stack_b)->next;
		ft_lstadd_backnum(stack_b, (*stack_b));
		(*stack_b) = tmp;
	}
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
}

void	do_rra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next != NULL)
	{
		head = (*stack_a);
		last = ft_lstlastnum((*stack_a));
		while ((*stack_a)->next != last)
			(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = NULL;
		last->next = head;
		(*stack_a) = last;
	}
}

void	do_rrb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next != NULL)
	{
		head = (*stack_b);
		last = ft_lstlastnum((*stack_b));
		while ((*stack_b)->next != last)
			(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = NULL;
		last->next = head;
		(*stack_b) = last;
	}
}
