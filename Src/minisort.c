/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:11:44 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/14 19:03:21 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	minisort3(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->num > (*stack_a)->next->next->num)
		ra(stack_a);
	if ((*stack_a)->next->num > (*stack_a)->next->next->num)
		rra(stack_a);
	if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->num > (*stack_a)->next->next->num)
		ra(stack_a);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
}

void	endsort5(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	minisort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	minisort5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*max;
	t_stack	*min;

	head = (*stack_a);
	max = (*stack_a);
	min = (*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->num > max->num)
			max = (*stack_a);
		else if ((*stack_a)->num < min->num)
			min = (*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head;
	if (max->next == NULL || min->next == NULL)
		rra(stack_a);
	while (*stack_a != max)
		ra(stack_a);
	pb(stack_a, stack_b);
	while (*stack_a != min)
		ra(stack_a);
	endsort5(stack_a, stack_b);
}
