/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:06:20 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 14:26:26 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"

typedef struct stack {
	int				content;
	struct stack	*next;
}	t_stack;
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_after_head(t_stack **stack);
t_stack		*ft_before_last(t_stack **stack);
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_sb(t_stack *stack);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack);
void		ft_rb(t_stack **stack);
void		ft_rra(t_stack **stack);
void		ft_rrb(t_stack **stack);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_sa(t_stack *stack);
int			ft_strcmp(const char *s1, const char *s2);
long long	ft_atoi(const char *str);

#endif