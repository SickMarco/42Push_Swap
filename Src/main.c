/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:51 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/13 17:47:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	int		pos;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	pos = 1;
	if (ac > 2 && check_args(av) == 0)
	{
		stack_a = ft_lstnewnum(ft_atoi(av[pos]));
		while (pos++ < ac - 1)
			ft_lstadd_backnum(&stack_a, ft_lstnewnum(ft_atoi(av[pos])));
		if (check_list(stack_a) == 1)
		{
			ft_printf("\033[0;31mError\nThere are duplicates\n\033[0;37m");
			free_list(&stack_a);
			return (1);
		}
		start_sorting(&stack_a, &stack_b, ac - 1);
		free_list(&stack_a);
		free_list(&stack_b);
	}
	else
		return (0);
}
