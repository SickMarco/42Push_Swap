/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:22 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/10 12:48:19 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_stack	*ft_lstnewnum(int num, char stack)
{
	t_stack	*new;

	if (stack == 'a')
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->sa.num = num;
		new->sa.next = NULL;
	}
	else if (stack == 'b')
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->sb.num = num;
		new->sb.next = NULL;
	}
	return (new);
}

void	ft_lstadd_backnum(t_stack **lst, t_stack *new, char stack)
{
	t_stack	*last;

	if (stack == 'a')
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->sa.next = new;
		}
		else
			*lst = new;
	}
	else if (stack == 'b')
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->sb.next = new;
		}
		else
			*lst = new;
	}
}

void	ft_lstadd_frontnum(t_stack **lst, t_stack *new, char stack)
{
	if (stack == 'a')
	{
		new->sa.next = *lst;
		*lst = new;
	}
	else if (stack == 'b')
	{
		new->sb.next = *lst;
		*lst = new;
	}
}
