/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:38:37 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/11 20:08:50 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/checker.h"

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
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
