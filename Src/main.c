/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:51 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/10 21:28:00 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	
	if (ac > 2 && check_args(av) == 0)
	{
		stack_a = malloc(sizeof(t_stack));
		stack_a->num = ft_atoi(av[--ac]);
		stack_a->next = NULL;
		while(--ac > 0)
			ft_lstadd_frontnum(&stack_a, ft_lstnewnum(ft_atoi(av[ac])));
		//check_list(stack_a);
	}
	else
		return (0);
}
