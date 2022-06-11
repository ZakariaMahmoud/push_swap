/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:10:57 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/11 09:01:01 by zmahmoud         ###   ########.fr       */
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
int			ft_strcmp(const char *s1, const char *s2);
int			arglen(char *args[]);
void		ft_check_int_range(int argc, char *args[]);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_sa(t_stack *stack, int print);
void		ft_sb(t_stack *stack, int print);
void		ft_ss(t_stack *stack_a, t_stack *stack_b, int print);
void		ft_ra(t_stack **stack, int print);
void		ft_rb(t_stack **stack, int print);
void		ft_rr(t_stack **stack_a, t_stack **stack_b, int print);
void		ft_rra(t_stack **stack, int print);
void		ft_rrb(t_stack **stack, int print);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b, int print);
void		ft_pa(t_stack **stack_a, t_stack **stack_b, int print);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int print);
void		min_to_top(t_stack **stack, int size, int position);
void		remove_top_stack(t_stack **stack);
void		remove_bottom_stack(t_stack **stack);
void		sort_array(t_stack *stack, t_helper *helper);
void		push_a_to_b(t_stack **stack_a, t_stack **stack_b, t_helper *helper);
void		push_b_to_a(t_stack **stack_a, t_stack **stack_b, t_helper *helper);
void		to_top_a(t_stack **stack, int position);
void		to_top_b(t_stack **stack, int position);
void		ft_check_args(int argc, char *args[]);
void		ft_check_duplicated(int argc, char *args[]);
void		sort_three_numbers(t_stack **stack);
void		sort_less_ten(t_stack **stack);
void		big_sort(t_stack **stack, int size);
void		print_helper_struct(t_helper *array);
void		init_helper(t_helper *helper, int size);
void		*ft_free(char **p);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*get_next_line(int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char **s1, char **s2);
char		*args_to_str(int argc, char *argv[]);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);

#endif
