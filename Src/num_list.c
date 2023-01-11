/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:22 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/11 18:44:34 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlastnum(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}


t_stack	*ft_lstnewnum(int num)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_backnum(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = ft_lstlastnum(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_frontnum(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
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

