/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:40:58 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/11 18:54:16 by mbozzi           ###   ########.fr       */
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

t_stack		*ft_lstnewnum(int num);
void		ft_lstadd_backnum(t_stack **lst, t_stack *new);
void		ft_lstadd_frontnum(t_stack **lst, t_stack *new);
int			check_args(char **av);
int			check_list(t_stack *stack);
t_stack		*ft_copy_list(t_stack *stack);
void		free_list(t_stack *list);
void		start_sorting(t_stack *stack_a);

#endif