/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:48:24 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/11 18:13:39 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_selector2(t_move **a, t_move **b, t_selector **sel, int i)
{
	if ((*a)->arr[i] <= 0 && (*b)->arr[i] >= 0)
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
		else if ((*a)->arr[i] < (*b)->arr[i]
			&& ft_abs((*a)->arr[i]) < (*sel)->best)
		{
			(*sel)->best = ft_abs((*a)->arr[i]);
			(*sel)->pos = i;
		}
	}
}

void	ft_selector1(t_move **a, t_move **b, t_selector **sel, int i)
{
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
}

void	ft_selector(t_move **a, t_move **b, t_selector **sel, int len)
{
	int	i;

	i = 0;
	(*sel)->best = INT_MAX;
	(*sel)->pos = 0;
	while (i < len)
	{
		if ((*sel)->best == 1 && (*sel)->pos == 0)
			break ;
		ft_selector1(a, b, sel, i);
		ft_selector2(a, b, sel, i);
		i++;
	}
}
