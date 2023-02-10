/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/10 16:05:54 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_a1(t_move **a, t_arr **arr, int i, int j)
{
	int			x;

	x = 0;
	if (((*arr)->arr_b[i] > (*arr)->arr_a[j]
			&& (*arr)->arr_b[i] < (*arr)->arr_a[j + 1])
		|| ((*arr)->arr_a[j] == (*arr)->find->max
			&& (*arr)->arr_a[j + 1] > (*arr)->arr_b[i])
		|| ((*arr)->arr_a[j + 1] == (*arr)->find->min
			&& (*arr)->arr_a[j] < (*arr)->arr_b[i]))
	{
		(*a)->arr[i] = j + 1;
		return (0);
	}
	return (1);
}

int	check_a2(t_move **a, t_arr **arr, int i, int j)
{
	int			x;

	x = 0;
	if (((*arr)->arr_b[i] > (*arr)->arr_a[j]
			&& (*arr)->arr_b[i] < (*arr)->arr_a[j + 1])
		|| ((*arr)->arr_a[j] == (*arr)->find->max
			&& (*arr)->arr_a[j + 1] > (*arr)->arr_b[i])
		|| ((*arr)->arr_a[j + 1] == (*arr)->find->min
			&& (*arr)->arr_a[j] < (*arr)->arr_b[i]))
	{
		(*a)->arr[i] = ((*a)->len_a - j) * -1 + 1;
		return (0);
	}
	return (1);
}

void	move_a(t_move **a, t_arr **arr)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (*a)->len_b)
	{
		j = -1;
		while (++j < (*a)->len_a)
		{
			if (j <= (*a)->len_a / 2)
			{
				if (check_a1(a, arr, i, j) == 0)
					break ;
			}
			else if (j >= (*a)->len_a / 2)
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
	(*b)->len_b = ft_lstsizenum(*stack_b);
	(*b)->arr = ft_calloc(sizeof(int), (*b)->len_b + 1);
	while (i++ < ((*b)->len_b / 2))
		(*b)->arr[i] = i;
	if ((*b)->len_b % 2 == 0)
		j = i - 2;
	else
		j = i - 1;
	while (i < (*b)->len_b)
	{
		(*b)->arr[i] = j-- *-1;
		i++;
	}
}

void	bigsort(t_stack **stack_a, t_stack **stack_b)
{
	t_bigsort	*bs;
	int			len;

	bs = ft_calloc(sizeof(t_bigsort), 1);
	ft_allocator(&bs);
	get_lis(stack_a, &bs->lis);
	push_lis(stack_a, stack_b, &bs->lis);
	while (*stack_b)
	{
		bs->arr->arr_a = lst_to_arr(stack_a);
		bs->arr->arr_b = lst_to_arr(stack_b);
		len = ft_lstsizenum(*stack_b);
		move_b(stack_b, &bs->b);
		bs->a->len_a = ft_lstsizenum(*stack_a);
		bs->a->len_b = ft_lstsizenum(*stack_b);
		bs->a->arr = ft_calloc(sizeof(int), ft_lstsizenum(*stack_b) + 1);
		bs->arr->find = intminmax(&bs->arr, bs->a->len_a);
		move_a(&bs->a, &bs->arr);
		free(bs->arr->find);
		ft_selector(&bs->a, &bs->b, &bs->best, len);
		ft_mover(stack_a, stack_b, &bs);
	}
	best_rotation(stack_a);
	free_for_all(&bs);
	free(bs);
}
