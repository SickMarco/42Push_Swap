/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:11:44 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/17 18:06:59 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_sort	find_minmax(t_stack **stack)
{
	t_sort	sort;
	t_stack	*head;

	head = (*stack);
	sort.max = head;
	sort.min = head;
	while (head)
	{
		if (head->num > sort.max->num)
			sort.max = head;
		else if (head->num < sort.min->num)
			sort.min = head;
		head = head->next;
	}
	return (sort);
}

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

void	minisort4(t_stack **stack_a, t_stack **stack_b)
{
	t_sort	sort;

	sort = find_minmax(stack_a);
	if (sort.max->next == NULL || sort.min->next == NULL)
		rra(stack_a);
	else
		while (*stack_a != sort.max && *stack_a != sort.min)
			ra(stack_a);
	pb(stack_a, stack_b);
	minisort3(stack_a);
	if (*stack_b == sort.max->next)
	{
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else
		pa(stack_a, stack_b);
}

void	minisort5(t_stack **stack_a, t_stack **stack_b)
{
	t_sort	sort;

	sort = find_minmax(stack_a);
	if (sort.max->next == NULL || sort.min->next == NULL)
		rra(stack_a);
	if (sort.max->next == NULL || sort.min->next == NULL)
		rra(stack_a);
	if ((*stack_a) == sort.min && sort.min->next == sort.max)
		sa(stack_a);
	while (*stack_a != sort.max && *stack_a != sort.min)
		ra(stack_a);
	pb(stack_a, stack_b);
	while (*stack_a != sort.min && *stack_a != sort.max)
		ra(stack_a);
	pb(stack_a, stack_b);
	minisort3(stack_a);
	if (*stack_b == sort.max)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}
