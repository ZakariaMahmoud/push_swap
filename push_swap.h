/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:10:57 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/06 11:37:05 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct stack {
	int				content;
	struct stack	*next;
}	t_stack;

typedef struct helper
{
	int	max;
	int	min;
	int	middle;
	int	size;
	int	down;
	int	*array;

}	t_helper;
t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_after_head(t_stack **stack);
t_stack		*ft_before_last(t_stack **stack);
long long	ft_atoi(const char *str);
int			get_min_position(t_stack *stack);
int			get_position(t_stack *stack, int value);
int			ft_lstsize(t_stack *lst);
int			ft_isdigit(int c);
int			is_sorted(t_stack *stack);
void		ft_check_int_range(int argc, char *argv[]);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_sa(t_stack *stack, int print);
void		ft_sb(t_stack *stack, int print);
void		ft_ra(t_stack **stack, int print);
void		ft_rra(t_stack **stack, int print);
void		ft_rb(t_stack **stack, int print);
void		ft_rrb(t_stack **stack, int print);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		min_to_top(t_stack **stack, int size, int position);
void		remove_top_stack(t_stack **stack);
void		remove_bottom_stack(t_stack **stack);
void		sort_array(t_stack *stack, t_helper *helper);
void		push_a_to_b(t_stack **stack_a, t_stack **stack_b, t_helper *helper);
void		push_b_to_a(t_stack **stack_a, t_stack **stack_b, t_helper *helper);
void		to_top_a(t_stack **stack, int position);
void		to_top_b(t_stack **stack, int position);
void		ft_check_args(int argc, char *argv[]);
void		ft_check_duplicated(int argc, char *argv[]);
void		sort_three_numbers(t_stack **stack);
void		sort_less_ten(t_stack **stack);
void		big_sort(t_stack **stack, int size);
void		print_helper_struct(t_helper *array);
void		init_helper(t_helper *helper, int size);

#endif