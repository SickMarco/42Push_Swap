/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:30:34 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/13 16:50:30 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_limits(char **av, int x)
{
	long int	num;

	num = ft_atoi_long(av[x]);
	if (num >= INT_MIN && num <= INT_MAX)
		return (0);
	else
	{
		ft_printf("\033[0;31mError\nSome arguments are bigger than an integer\n");
		ft_printf("Some arguments are bigger than an integer\n\033[0;37m");
	}
	return (1);
}

int	check_args(char **av)
{
	int			x;
	int			y;

	x = 0;
	while (av[++x])
	{
		y = 0;
		if (check_limits(av, x) == 1)
			return (1);
		if (av[x][0] == '-')
			y++;
		while (av[x][y])
		{
			if ((av[x][y] >= '0' && av[x][y] <= '9'))
				y++;
			else
			{
				ft_printf("\033[0;31mError\n");
				ft_printf("Some arguments aren’t integers\n\033[0;37m");
				return (1);
			}
		}
	}
	return (0);
}

int	check_list(t_stack *stack)
{
	int		counter;
	t_stack	*copy;
	t_stack	*chead;

	copy = ft_copy_list(stack);
	chead = copy;
	while (stack)
	{
		copy = chead;
		counter = 0;
		while (copy)
		{
			if (copy->num == stack->num)
				counter ++;
			if (counter > 1)
			{
				free_list(&chead);
				return (1);
			}
			copy = copy->next;
		}
		stack = stack->next;
	}
	free_list(&chead);
	return (0);
}
