/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/08 18:00:01 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a1(t_move **a, t_arr **arr, int i, int j)
{
	int			x;
	t_minmax	*find;

	x = 0;
	find = intminmax(arr);
	if (((*arr)->arr_b[i] > (*arr)->arr_a[j]
			&& (*arr)->arr_b[i] < (*arr)->arr_a[j + 1])
		|| ((*arr)->arr_a[j] == find->max
			&& (*arr)->arr_a[j + 1] > (*arr)->arr_b[i])
		|| ((*arr)->arr_a[j + 1] == find->min
			&& (*arr)->arr_a[j] < (*arr)->arr_b[i]))
	{
		(*a)->arr[i] = j + 1;
		free(find);
		return (0);
	}
	free(find);
	return (1);
}

int	check_a2(t_move **a, t_arr **arr, int i, int j)
{
	int			x;
	t_minmax	*find;

	x = 0;
	find = intminmax(arr);
	if (((*arr)->arr_b[i] > (*arr)->arr_a[j]
			&& (*arr)->arr_b[i] < (*arr)->arr_a[j + 1])
		|| ((*arr)->arr_a[j] == find->max
			&& (*arr)->arr_a[j + 1] > (*arr)->arr_b[i])
		|| ((*arr)->arr_a[j + 1] == find->min
			&& (*arr)->arr_a[j] < (*arr)->arr_b[i]))
	{
		(*a)->arr[i] = ((*a)->len - j) * -1 + 1;
		free(find);
		return (0);
	}
	free(find);
	return (1);
}

void	move_a(t_stack **stack_a, t_stack **stack_b, t_move **a, t_arr **arr)
{
	int		i;
	int		j;

	i = -1;
	(*a)->len = ft_lstsizenum(*stack_a);
	(*a)->arr = ft_calloc(sizeof(int), ft_lstsizenum(*stack_b) + 1);
	while ((*arr)->arr_b[++i])
	{
		j = -1;
		while ((*arr)->arr_a[++j])
		{
			if (j < (*a)->len / 2)
			{
				if (check_a1(a, arr, i, j) == 0)
					break ;
			}
			else if (j >= (*a)->len / 2)
			{
				if (check_a2(a, arr, i, j) == 0)
					break ;
			}
		}
	}
	free((*arr)->arr_a);
	free((*arr)->arr_b);
}

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
	t_bigsort	*bs;

	bs = ft_calloc(sizeof(t_bigsort), 1);
	ft_allocator(&bs);
	get_lis(stack_a, &bs->lis);
	push_lis(stack_a, stack_b, &bs->lis);
	free_lis(&bs->lis);
	while (*stack_b)
	{
		bs->arr->arr_a = lst_to_arr(stack_a);
		bs->arr->arr_b = lst_to_arr(stack_b);
		move_b(stack_b, &bs->b);
		move_a(stack_a, stack_b, &bs->a, &bs->arr);
		ft_selector(&bs->a, &bs->b, &bs->best);
		ft_mover(stack_a, stack_b, &bs);
	}
	best_rotation(stack_a);
	free(bs->arr);
	free(bs->a);
	free(bs->b);
	free(bs->best);
	free(bs);
}
