/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/10 12:49:00 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./MyLib/mylib.h"

typedef struct s_stack_a {
	int					num;
	struct s_stack_a	*next;
}				t_stack_a;

typedef struct s_stack_b {
	int					num;
	struct s_stack_b	*next;
}				t_stack_b;

typedef struct s_stack {
	t_stack_a	sa;
	t_stack_b	sb;
}				t_stack;

t_stack		*ft_lstnewnum(int num, char stack);
void		ft_lstadd_backnum(t_stack **lst, t_stack *new, char stack);
void		ft_lstadd_frontnum(t_stack **lst, t_stack *new, char stack);

#endif