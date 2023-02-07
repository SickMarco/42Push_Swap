/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:58:03 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/05 16:24:00 by mbozzi           ###   ########.fr       */
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

int	*lst_to_arr(t_stack **stack_a)
{
	t_stack	*stack;
	int		*arr;
	int		x;
	int		size;

	x = 0;
	stack = (*stack_a);
	size = ft_lstsizenum(*stack_a);
	arr = ft_calloc(sizeof(int), size + 1);
	while (stack)
	{
		arr[x] = stack->num;
		x++;
		stack = stack->next;
	}
	return (arr);
}

void	free_list(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_stack	*ft_copy_list(t_stack *stack)
{
	t_stack	*copy;

	copy = ft_lstnewnum (stack->num);
	while (stack->next != NULL)
	{
		stack = stack->next;
		ft_lstadd_backnum(&copy, ft_lstnewnum(stack->num));
	}
	return (copy);
}

void	ft_printlist(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nA\n");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("\nB\n");
	while (stack_b)
	{
		ft_printf("%d ", stack_b->num);
		stack_b = stack_b->next;
	}
}
