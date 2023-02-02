/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/02 17:24:02 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bigsort(t_stack **stack_a, t_stack **stack_b)
{
	t_lis	*lis;

	lis = ft_calloc(sizeof(t_lis), 1);
	get_lis(stack_a, &lis);
	push_lis(stack_a, stack_b, &lis);
	free_lis(&lis);
}
