/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:11:44 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/13 18:16:44 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	minisort3(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = NULL;
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
