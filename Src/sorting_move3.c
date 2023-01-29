/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_move3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:58:03 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/29 18:04:50 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printer("rrr");
	rra(stack_a);
	rrb(stack_b);
	ft_printer("OFF");
}

void	ft_printer(char	*mov)
{
	static int	flag = 0;

	if (ft_strncmp(mov, "OFF", 4) == 0)
	{
		flag = 0;
		return ;
	}
	if (ft_strncmp(mov, "ss", 3) == 0 || ft_strncmp(mov, "rrr", 4) == 0
		|| ft_strncmp(mov, "rr", 3) == 0)
	{
		flag = 1;
		ft_printf("%s\n", mov);
	}
	if (flag == 0)
		ft_printf("%s\n", mov);
}
