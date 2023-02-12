/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:11 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/12 18:16:55 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next != NULL)
	{
		tmp = (*stack_a)->next;
		ft_lstadd_backnum(stack_a, (*stack_a));
		(*stack_a) = tmp;
		ft_printer("ra");
	}
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b && (*stack_b)->next != NULL)
	{
		tmp = (*stack_b)->next;
		ft_lstadd_backnum(stack_b, (*stack_b));
		(*stack_b) = tmp;
		ft_printer("rb");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printer("rr");
	ra(stack_a);
	rb(stack_b);
	ft_printer("OFF");
}

void	rra(t_stack **stack_a)
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
		ft_printer("rra");
	}
}

void	rrb(t_stack **stack_b)
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
		ft_printer("rrb");
	}
}
