/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:34:45 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/07 18:03:05 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return(i);
}

void	ft_mover(t_stack **stack_a, t_stack **stack_b, t_bigsort **bs)
{
	int i;
	int	x;
	int y;
	i = 0;

	x = (*bs)->a->arr[(*bs)->best->pos];
	y = (*bs)->b->arr[(*bs)->best->pos];
	if (*stack_b)
	{
		if (x >= 0 && y>= 0)
		{
			while (i < x && i < y)
			{
				rr(stack_a, stack_b);
				i++;
			}
			while (i < x || i < y)
			{
				if (i < x)
					ra(stack_a);
				else if (i < y)
					rb(stack_b);
				i++;
			}
			pa(stack_a, stack_b);
		}
		else if (x >= 0 && y <= 0)
		{
			while (i < x)
			{
				ra(stack_a);
				i++;
			}
			while (y < 0)
			{
				rrb(stack_b);
				y++;
			}
			pa(stack_a, stack_b);
		}
		else if (x <= 0 && y >= 0)
		{
			while(x < 0)
			{
				rra(stack_a);
				x++;
			}
			while(i < y)
			{
				rb(stack_b);
				i++;
			}
			pa(stack_a, stack_b);
		}
		else if (x <= 0 && y <= 0)
		{
			while (x < 0 && y < 0)
			{
				rrr(stack_a, stack_b);
				x++;
				y++;
			}
			while (x < 0 || y < 0)
			{
				if (x < 0)
				{
					rra(stack_a);
					x++;
				}
				else if (y < 0)
				{
					rrb(stack_b);
					y++;
				}
			}
			pa(stack_a, stack_b);
		}
	}
	free((*bs)->a->arr);
	free((*bs)->b->arr);
}

void	ft_selector(t_move **a, t_move **b, t_selector **sel)
{
	int	i;

	i = 0;
	(*sel)->best = 500;
	(*sel)->pos = 0;
	while ((*a)->arr[i] || (*b)->arr[i])
	{
		if ((*sel)->best == 1 && (*sel)->pos == 0)
			break ;
		if ((*a)->arr[i] >= 0 && (*b)->arr[i] >= 0)
		{   
			if ((*a)->arr[i] > (*b)->arr[i] && (*a)->arr[i] < (*sel)->best)
			{
				(*sel)->best = (*a)->arr[i];
				(*sel)->pos = i;
			}
			else if ((*a)->arr[i] < (*b)->arr[i] && (*b)->arr[i] < (*sel)->best)
			{
				(*sel)->best = (*b)->arr[i];
				(*sel)->pos = i;
			}
		}
		else if ((*a)->arr[i] >= 0 && (*b)->arr[i] <= 0)
		{
			if ((*a)->arr[i] + ft_abs((*b)->arr[i]) < (*sel)->best)
			{
				(*sel)->best = (*a)->arr[i] + ft_abs((*b)->arr[i]);
				(*sel)->pos = i;
			}
		}
		else if ((*a)->arr[i] <= 0 && (*b)->arr[i] >= 0)
		{
			if (ft_abs((*a)->arr[i]) + (*b)->arr[i] < (*sel)->best)
			{
				(*sel)->best = ft_abs((*a)->arr[i]) + (*b)->arr[i];
				(*sel)->pos = i;
			}
		}
		else if ((*a)->arr[i] <= 0 && (*b)->arr[i] <= 0)
		{
			if ((*a)->arr[i] > (*b)->arr[i] && ft_abs((*b)->arr[i]) < (*sel)->best)
			{
				(*sel)->best = ft_abs((*b)->arr[i]);
				(*sel)->pos = i;
			}
			else if ((*a)->arr[i] < (*b)->arr[i] && ft_abs((*a)->arr[i]) < (*sel)->best)
			{
				(*sel)->best = ft_abs((*a)->arr[i]);
				(*sel)->pos = i;
			}
		}
		i++;
	}
}

void	move_a(t_stack **stack_a, t_stack **stack_b, t_move **a, t_arr **arr)
{
	int		i;
	int		j;
	int		lenght;
	int 	max = 0;
	int		min = 500;
	
	i = 0;
	lenght = ft_lstsizenum(*stack_a);
	(*a)->len = ft_lstsizenum(*stack_b);
	(*a)->arr = ft_calloc(sizeof(int), (*a)->len + 1);
	(*arr)->arr_a = lst_to_arr(stack_a);
	(*arr)->arr_b = lst_to_arr(stack_b);
	while ((*arr)->arr_a[i])
	{
		if (((*arr)->arr_a[i]) > max)
			max = (*arr)->arr_a[i];
		else if (((*arr)->arr_a[i]) < min)
			min = (*arr)->arr_a[i];
		i++;
	}
	i = 0;
	while ((*arr)->arr_b[i])
	{
		j = 0;
		while ((*arr)->arr_a[j])
		{
			if (j < lenght / 2)
			{
				if ((*arr)->arr_b[i] > (*arr)->arr_a[j] && (*arr)->arr_b[i] < (*arr)->arr_a[j + 1])
				{
					(*a)->arr[i] = j + 1;
					break ;
				}
				else if ((*arr)->arr_a[j] == max && (*arr)->arr_a[j + 1] > (*arr)->arr_b[i])
					(*a)->arr[i] = j + 1;
				else if ((*arr)->arr_a[j + 1] == min && (*arr)->arr_a[j] < (*arr)->arr_b[i])
					(*a)->arr[i] = j + 1;
			}
			else if (j >= lenght / 2)
			{
				if ((*arr)->arr_b[i] > (*arr)->arr_a[j] && (*arr)->arr_b[i] < (*arr)->arr_a[j + 1])
				{
						(*a)->arr[i] = (lenght - j) *-1 + 1;
					break ;
				}
				else if ((*arr)->arr_a[j] == max && (*arr)->arr_a[j + 1] > (*arr)->arr_b[i])
					(*a)->arr[i] = (lenght - j) *-1 + 1;
				else if ((*arr)->arr_a[j + 1] == min && (*arr)->arr_a[j] < (*arr)->arr_b[i])
					(*a)->arr[i] = (lenght - j) *-1 + 1;
			}
			j++;
		}
		i++;
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
	t_bigsort *bs;

	bs = ft_calloc(sizeof(t_bigsort), 1);
	bs->lis = ft_calloc(sizeof(t_lis), 1);
	bs->a = ft_calloc(sizeof(t_move), 1);
	bs->b = ft_calloc(sizeof(t_move), 1);
	bs->arr = ft_calloc(sizeof(t_arr), 1);
	bs->best = ft_calloc(sizeof(t_selector), 1);
	get_lis(stack_a, &bs->lis);
	push_lis(stack_a, stack_b, &bs->lis);
	free_lis(&bs->lis);
	int	i = 0;
	while (*stack_b)
	{
		move_b(stack_b, &bs->b);
		move_a(stack_a, stack_b, &bs->a, &bs->arr);
		ft_selector(&bs->a, &bs->b, &bs->best);
		ft_mover(stack_a, stack_b, &bs);
		i++;
	}
	while (ft_sorted(stack_a) != 1)
		ra(stack_a);
	free(bs);
}
