/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/17 18:08:41 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bigsort(t_stack **stack_a, t_stack **stack_b)
{
	t_sort	sort_a;
	int		half;
	int 	i;

	sort_a = find_minmax(stack_a);
	half = (sort_a.max->num + sort_a.min->num) / 2;
	i = ft_lstsizenum(*stack_a);
	while (i--)
	{
		if ((*stack_a)->num > half)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	autosorting(stack_a, stack_b);
}
