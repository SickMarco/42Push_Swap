/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/02/08 17:52:08 by mbozzi           ###   ########.fr       */
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

typedef struct s_lis {
	int					*arr;
	int					size;
	int					*lis;
	int					*sub;
	int					*len;
	int					best;
	int					max_len;
	int					max;
}				t_lis;

typedef struct s_move {
	int					*arr;
	int					len;
}				t_move;

typedef struct s_arr {
	int					*arr_a;
	int					*arr_b;
}				t_arr;

typedef struct s_selector {
	int					best;
	int					pos;
}				t_selector;

typedef struct s_bigsort {
	t_lis			*lis;
	t_move			*a;
	t_move			*b;
	t_arr			*arr;
	t_selector		*best;

}				t_bigsort;

typedef struct s_minmax {
	int					min;
	int					max;
}				t_minmax;

//			LIST UTILS				//

t_stack		*ft_lstnewnum(int num);
void		ft_lstadd_backnum(t_stack **lst, t_stack *new);
void		ft_lstadd_frontnum(t_stack **lst, t_stack *new);
t_stack		*ft_lstlastnum(t_stack *lst);
t_stack		*ft_copy_list(t_stack *stack);
void		free_list(t_stack **list);
int			ft_lstsizenum(t_stack *lst);
int			*lst_to_arr(t_stack **stack_a);
void		ft_printlist(t_stack *stack_a, t_stack *stack_b);

// 				MOVES				//

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
void		ft_printer(char	*mov);

//				SORTING				//

void		start_sorting(t_stack **stack_a, t_stack **stack_b, int ac);
t_sort		find_minmax(t_stack **stack);
void		minisort3(t_stack **stack_a);
void		minisort4(t_stack **stack_a, t_stack **stack_b);
void		minisort5(t_stack **stack_a, t_stack **stack_b);
void		bigsort(t_stack **stack_a, t_stack **stack_b);
void		get_lis(t_stack **stack_a, t_lis **lis);
void		free_lis(t_lis **lis);
void		push_lis(t_stack **stack_a, t_stack **stack_b, t_lis **lis);
void		ft_allocator(t_bigsort **bs);
int			ft_abs(int i);
t_minmax	*intminmax(t_arr **arr);
void		ft_selector(t_move **a, t_move **b, t_selector **sel);
void		ft_mover(t_stack **stack_a, t_stack **stack_b, t_bigsort **bs);
void		move_plusplus(t_stack **stack_a, t_stack **stack_b, int x, int y);
void		move_plusminus(t_stack **stack_a, t_stack **stack_b, int x, int y);
void		move_minusplus(t_stack **stack_a, t_stack **stack_b, int x, int y);
void		move_minusminus(t_stack **stack_a, t_stack **stack_b, int x, int y);
void		best_rotation(t_stack **stack_a);

//				CHECKS				//

int			check_args(char **av);
int			check_list(t_stack *stack);
int			ft_sorted(t_stack **stack_a);

#endif
