/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:51 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/10 17:26:49 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	start_sorting(t_stack **stack_a, t_stack **stack_b, int ac)
{
	if (ft_sorted(stack_a) == 1)
		return ;
	if (ac == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
	}
	else if (ac == 3)
		minisort3(stack_a);
	else if (ac == 4)
		minisort4(stack_a, stack_b);
	else if (ac == 5)
		minisort5(stack_a, stack_b);
	else
		bigsort(stack_a, stack_b);
}

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
