/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:53:16 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/15 17:36:31 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_printlist(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nA\n");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("\nB\n");
	while (stack_b)
	{
		ft_printf("%d ", stack_b->num);
		stack_b = stack_b->next;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	start_sorting(t_stack **stack_a, t_stack **stack_b, int ac)
{
	if (ac == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
	}
	if (ac == 3)
		minisort3(stack_a);
	if (ac == 5)
		minisort5(stack_a, stack_b);
	ft_printlist(*stack_a, *stack_b);
}
