/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:46:53 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/10 17:50:52 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_allocator(t_bigsort **bs)
{
	(*bs)->lis = ft_calloc(sizeof(t_lis), 1);
	(*bs)->a = ft_calloc(sizeof(t_move), 1);
	(*bs)->b = ft_calloc(sizeof(t_move), 1);
	(*bs)->arr = ft_calloc(sizeof(t_arr), 1);
	(*bs)->best = ft_calloc(sizeof(t_selector), 1);
}

t_minmax	*intminmax(t_arr **arr, int len)
{
	int			x;
	t_minmax	*find;

	x = 0;
	find = calloc(sizeof(t_minmax), 1);
	find->max = INT_MIN;
	find->min = INT_MAX;
	while (x < len)
	{
		if (((*arr)->arr_a[x]) > find->max)
			find->max = (*arr)->arr_a[x];
		if (((*arr)->arr_a[x]) < find->min)
			find->min = (*arr)->arr_a[x];
		x++;
	}
	return (find);
}

int	ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void	best_rotation(t_stack **stack_a)
{
	t_sort	sort;
	t_stack	*copy;
	int		len;
	int		pos;

	pos = 0;
	sort = find_minmax(stack_a);
	len = ft_lstsizenum(*stack_a);
	copy = *stack_a;
	while (copy != sort.min)
	{
		pos++;
		copy = copy->next;
	}
	if (pos < len / 2)
	{
		while ((*stack_a) != sort.min)
			ra(stack_a);
	}
	else if (pos >= len / 2)
	{
		while ((*stack_a) != sort.min)
			rra(stack_a);
	}
}

void	free_for_all(t_bigsort **bs)
{
	free((*bs)->arr);
	free((*bs)->a);
	free((*bs)->b);
	free((*bs)->best);
}
