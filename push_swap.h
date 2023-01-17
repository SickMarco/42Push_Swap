/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/17 17:10:13 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Src/MyLib/mylib.h"
# include <limits.h>

typedef struct s_stack {
	int					num;
	struct s_stack		*next;
}				t_stack;

typedef struct s_sort {
	t_stack				*max;
	t_stack				*min;
}				t_sort;

t_stack		*ft_lstnewnum(int num);
void		ft_lstadd_backnum(t_stack **lst, t_stack *new);
void		ft_lstadd_frontnum(t_stack **lst, t_stack *new);
t_stack		*ft_lstlastnum(t_stack *lst);
int			check_args(char **av);
int			check_list(t_stack *stack);
t_stack		*ft_copy_list(t_stack *stack);
void		free_list(t_stack **list);
int			ft_lstsizenum(t_stack *lst);
void		start_sorting(t_stack **stack_a, t_stack **stack_b, int ac);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
t_sort		find_minmax(t_stack **stack);
void		minisort3(t_stack **stack_a);
void		minisort4(t_stack **stack_a, t_stack **stack_b);
void		minisort5(t_stack **stack_a, t_stack **stack_b);
void		bigsort(t_stack **stack_a, t_stack **stack_b);

#endif