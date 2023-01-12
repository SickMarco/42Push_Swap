/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:11 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/12 19:52:36 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = (*stack_a)->next;
	ft_lstadd_backnum(stack_a, (*stack_a));
	(*stack_a) = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	t_stack *tmp;

	tmp = (*stack_b)->next;
	ft_lstadd_backnum(stack_b, (*stack_b));
	(*stack_b) = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack *head;
	t_stack	*last;

	head = (*stack_a);
	last = ft_lstlastnum((*stack_a));
	while ((*stack_a)->next != last)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = NULL;
	last->next = head;
	(*stack_a) = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack *head;
	t_stack	*last;

	head = (*stack_b);
	last = ft_lstlastnum((*stack_b));
	while ((*stack_b)->next != last)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = NULL;
	last->next = head;
	(*stack_b) = last;
	ft_printf("rrb\n");
}


