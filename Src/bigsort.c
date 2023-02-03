/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/03 20:03:24 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_b(t_stack **stack_b, t_move **b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(*b)->len = ft_lstsizenum(*stack_b);
	(*b)->arr = ft_calloc(sizeof(int), (*b)->len + 1);
	while (i++ < ((*b)->len / 2))
		(*b)->arr[i] = i;
	if ((*b)->len % 2 == 0)
		j = i - 2;
	else
		j = i - 1;
	while (i < (*b)->len)
	{
		(*b)->arr[i] = j-- *-1;
		i++;
	}
}

void	bigsort(t_stack **stack_a, t_stack **stack_b)
{
	t_lis	*lis;
	t_move	*a;
	t_move	*b;

	lis = ft_calloc(sizeof(t_lis), 1);
	a = ft_calloc(sizeof(t_move), 1);
	b = ft_calloc(sizeof(t_move), 1);
	get_lis(stack_a, &lis);
	push_lis(stack_a, stack_b, &lis);
	free_lis(&lis);
	move_b(stack_b, &b);
}
