/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/26 19:23:54 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_b(t_stack **stack_a, t_stack **stack_b, t_sort sort)
{
	t_stack *last;

	last = ft_lstlastnum(*stack_a);
	while (*stack_b)
	{
		ft_printf ("%d, %d, %d -> ", (*stack_a)->num, (*stack_b)->num, (*stack_a)->next->num);
		if ((*stack_a)->num < (*stack_b)->num && (*stack_a)->next->num > (*stack_b)->num)
		{
			ra(stack_a);
			pa(stack_a, stack_b);
			rra(stack_a);
		}
		else if ((*stack_b)->num > last->num && (*stack_a) == last)
		{
			pa(stack_a, stack_b);
			last = (*stack_a);
			sa(stack_a);
			ra(stack_a);
			ra(stack_a);
		}
		else if ((*stack_b) == sort.min && (*stack_a) == last)
		{
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
			ra(stack_a);
	}
	while (ft_sorted(stack_a) != 1)
		rra(stack_a);
}

void	lis_check(t_lis *lis)
{
	if (lis->len < lis->tmp)
	{
		lis->len = lis->tmp;
		lis->start = lis->fst;
		lis->end = lis->lst;
	}
	return ;
}

t_lis	*find_lis(t_stack **stack_a)
{
	t_stack	*start;
	t_lis	*lis;

	lis = ft_calloc(sizeof(t_lis), 1);
	lis->len = 0;
	start = (*stack_a);
	while (start->next != NULL)
	{
		lis->tmp = 0;
		if (start->num < start->next->num)
		{
			lis->fst = start->num;
			while (start->num < start->next->num && start->next->next != NULL)
			{
				lis->lst = start->next->num;
				lis->tmp++;
				start = start->next;
			}
			lis_check(lis);
			start = start->next;
		}
		else
			start = start->next;
	}
	return (lis);
}

void	bigsort(t_stack **stack_a, t_stack **stack_b)
{
	t_lis	*lis;
	t_sort	sort;
	
	sort = find_minmax(stack_a);
	lis = find_lis(stack_a);
	while ((*stack_a)->num != lis->start)
		pb(stack_a, stack_b);
	while ((*stack_a)->num != lis->end)
		ra(stack_a);
	ra(stack_a);
	while ((*stack_a)->num != lis->start)
		pb(stack_a, stack_b);
	sort_b(stack_a, stack_b, sort);
	free(lis);
}