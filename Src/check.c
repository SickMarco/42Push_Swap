/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:30:34 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/10 21:27:22 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_args(char **av)
{
	int		x;
	int		y;

	x = 1;
	while (av[x])
	{
		y = 0;
		if (av[x][0] == '-')
			y++;
		while (av[x][y])
		{
			if ((av[x][y] >= '0' && av[x][y] <= '9'))
				y++;
			else
			{
				ft_printf("Wrong Arguments\n");
				return (1);
			}
		}
		x++;
	}
	return (0);
}

/*int	check_list(t_stack *stack)
{
	
}*/