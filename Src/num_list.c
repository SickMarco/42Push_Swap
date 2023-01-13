/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:22 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/13 17:10:50 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	new = malloc(sizeof(t_stack));
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
		new->next = NULL;
	}
	else
		*lst = new;
}

void	ft_lstadd_frontnum(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
