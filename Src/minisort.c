/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:11:44 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/14 19:45:58 by mbozzi           ###   ########.fr       */
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

void	endsort5(t_stack **stack_a, t_stack **stack_b, t_sort sort)
{
	while (*stack_a != sort.max)
		ra(stack_a);
	pb(stack_a, stack_b);
	while (*stack_a != sort.min)
		ra(stack_a);
	pb(stack_a, stack_b);
	minisort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	minisort5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_sort	sort;

	head = (*stack_a);
	sort.max = (*stack_a);
	sort.min = (*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->num > sort.max->num)
			sort.max = (*stack_a);
		else if ((*stack_a)->num < sort.min->num)
			sort.min = (*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head;
	if (sort.max->next == NULL)
		rra(stack_a);
	if ((*stack_a) == sort.min && sort.min->next == sort.max)
		sa(stack_a);
	endsort5(stack_a, stack_b, sort);
}