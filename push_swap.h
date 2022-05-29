#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stack {
    int content;
    struct stack	*next;
}  t_stack;

t_stack *ft_lstlast(t_stack *lst);
t_stack *ft_lstnew(int	content);
t_stack *ft_before_last(t_stack **stack);
t_stack *ft_after_head(t_stack **stack);
int     get_min(t_stack *stack, int *position);
int	    ft_lstsize(t_stack *lst);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_sa(t_stack *stack, int print);
void    ft_sb(t_stack *stack, int print);
void    ft_ra(t_stack **stack, int print);
void    ft_rra(t_stack **stack, int print);
void    ft_rb(t_stack **stack, int print);
void    ft_rrb(t_stack **stack, int print);
void    ft_rr(t_stack **stack_a, t_stack **stack_b);
void    ft_rrr(t_stack **stack_a, t_stack **stack_b);
void    ft_pa(t_stack **stack_a, t_stack **stack_b);
void    ft_pb(t_stack **stack_a, t_stack **stack_b);
void    min_to_top(t_stack **stack, int size, int position);
void    print_stack(t_stack *stack, char *msg);
void    remove_top_stack(t_stack **stack);
void    remove_bottom_stack(t_stack **stack);
void    print_array(int *array, int capacity);
void    push_to_array(t_stack *stack, int *array, int capacity);
void    sort_array(int *array, int capacity);
void	ft_lstiter(t_stack *lst, int min, int max, void (*f)(int, int, int));
void    push_to_b(t_stack **stack_a, t_stack **stack_b, int max, int min, int middle, int *array);
void    to_top(t_stack **stack, int position);
int     in_range(t_stack *stack, int max, int min);


// void    ft_sa(Stack *stack);
// void    ft_sb(Stack *stack);
// void    ft_ss(Stack *stack_a, Stack *stack_b);
// void    ft_ra(Stack *stack);
// void    ft_rb(Stack *stack);
// void    ft_rr(Stack *stack_a, Stack *stack_b);
// void    ft_rra(Stack *stack);
// void    ft_rrb(Stack *stack);
// void    ft_pa(Stack *stack_a, Stack *stack_b);
// void    ft_pb(Stack *stack_a, Stack *stack_b);
// void	ft_check(int argc, char *argv[]);
// void    ft_check_duplicated(int argc, char *argv[]);
// void    push(Stack *stack, int item);
// void    sort_three_numbers(Stack *stack);
// void    print_stack(Stack *stack);
// int     ft_atoi(const char *str);
// int		ft_isdigit(int c);
// int     is_sorted(Stack *stack);


// Stack   *createStack(unsigned capacity);
#endif


//    1 2 3
// 1 3 2
//    2 1 3
// 2 3 1
//    3 1 2
//    3 2 1