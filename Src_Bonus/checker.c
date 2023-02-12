/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:07:40 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/12 18:47:55 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/checker.h"

int	do_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if ((ft_strncmp(line, "rra\n", 5) == 0))
		do_rra(stack_a);
	else if ((ft_strncmp(line, "rrb\n", 5) == 0))
		do_rrb(stack_b);
	else if ((ft_strncmp(line, "rrr\n", 5) == 0))
		do_rrr(stack_a, stack_b);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		do_sa(stack_a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		do_sb(stack_b);
	else if ((ft_strncmp(line, "ss\n", 4) == 0))
		do_ss(stack_a, stack_b);
	else if ((ft_strncmp(line, "pa\n", 4) == 0))
		do_pa(stack_a, stack_b);
	else if ((ft_strncmp(line, "pb\n", 4) == 0))
		do_pb(stack_a, stack_b);
	else if ((ft_strncmp(line, "ra\n", 4) == 0))
		do_ra(stack_a);
	else if ((ft_strncmp(line, "rb\n", 4) == 0))
		do_rb(stack_b);
	else if ((ft_strncmp(line, "rr\n", 4) == 0))
		do_rr(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	create_list(t_stack **stack_a, int ac, char **av)
{
	int		pos;

	pos = 1;
	(*stack_a) = ft_lstnewnum(ft_atoi(av[pos]));
	while (pos++ < ac - 1)
		ft_lstadd_backnum(stack_a, ft_lstnewnum(ft_atoi(av[pos])));
	if (check_list(*stack_a) == 1)
	{
		ft_printf("\033[0;31mError\nThere are duplicates\n\033[0;37m");
		free_list(stack_a);
		return (1);
	}
	return (0);
}

void	get_op(t_stack **stack_a, t_stack **stack_b, int *error)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		*error = do_op(stack_a, stack_b, line);
		if (*error == 1)
		{
			ft_printf("\033[0;31mError\n\033[0;37m");
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				error;

	stack_b = NULL;
	error = 0;
	if (ac > 2 && check_args(av) == 0)
	{
		if (create_list(&stack_a, ac, av) == 0)
		{
			get_op(&stack_a, &stack_b, &error);
			if (ft_sorted(&stack_a) == 1 && error == 0)
				ft_printf("OK\n");
			else if (ft_sorted(&stack_a) != 1 && error == 0)
				ft_printf("KO\n");
			free_list(&stack_a);
			free_list(&stack_b);
		}
	}
	return (0);
}
