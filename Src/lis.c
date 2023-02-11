/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:27:13 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/10 17:26:42 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//		LONGEST INCREASING SUBSEQUENCE		//

void	lis_alloc(t_stack **stack_a, t_lis **lis)
{
	int	i;

	i = 0;
	(*lis)->arr = lst_to_arr(stack_a);
	(*lis)->size = ft_lstsizenum(*stack_a);
	(*lis)->len = ft_calloc(sizeof(int), (*lis)->size + 1);
	(*lis)->sub = ft_calloc(sizeof(int), (*lis)->size + 1);
	while (i < (*lis)->size)
	{
		(*lis)->len[i] = 1;
		(*lis)->sub[i] = -1;
		i++;
	}
}

void	lis_finder(t_lis **lis, int size)
{
	int	i;

	i = 0;
	(*lis)->max_len = 0;
	(*lis)->max = 0;
	while (i < size)
	{
		if ((*lis)->len[i] > (*lis)->max_len)
		{
			(*lis)->max_len = (*lis)->len[i];
			(*lis)->max = (*lis)->arr[i];
			(*lis)->best = (*lis)->sub[i];
		}
		i++;
	}
	(*lis)->lis = ft_calloc(sizeof(int), (*lis)->max_len + 1);
	i = (*lis)->best;
	(*lis)->max_len--;
	(*lis)->lis[(*lis)->max_len] = (*lis)->max;
	while ((*lis)->max_len--)
	{
		(*lis)->lis[(*lis)->max_len] = (*lis)->arr[i];
		i = (*lis)->sub[i];
	}
}

void	get_lis(t_stack **stack_a, t_lis **lis)
{
	int	i;
	int	j;

	lis_alloc(stack_a, lis);
	i = 1;
	while (i < (*lis)->size)
	{
		j = 0;
		while (j < i)
		{
			if ((*lis)->arr[j] < (*lis)->arr[i])
			{
				if ((*lis)->len[i] < (*lis)->len[j] + 1)
				{
					(*lis)->len[i] = (*lis)->len[j] + 1;
					(*lis)->sub[i] = j;
				}
			}
			j++;
		}
		i++;
	}
	lis_finder(lis, (*lis)->size);
}

void	push_lis(t_stack **stack_a, t_stack **stack_b, t_lis **lis)
{
	int	i;

	i = 0;
	while ((*stack_a)->num != (*lis)->lis[0])
		pb(stack_a, stack_b);
	ra(stack_a);
	i++;
	while ((*stack_a)->num != (*lis)->lis[0])
	{
		if ((*stack_a)->num == 0)
			pb(stack_a, stack_b);
		else if ((*stack_a)->num == (*lis)->lis[i])
		{
			ra(stack_a);
			i++;
		}
		else
			pb (stack_a, stack_b);
	}
	free((*lis)->arr);
	free((*lis)->len);
	free((*lis)->sub);
	free((*lis)->lis);
	free(*lis);
}
