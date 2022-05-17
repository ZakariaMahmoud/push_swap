#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stack {
    int content;
    struct stack	*next;
}  t_stack;

t_stack *ft_lstnew(int	content);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_sa(t_stack *stack);

int	ft_isdigit(int c);
int	ft_atoi(const char *str);


// void    ft_sa(Stack *stack);
// void    ft_sb(Stack *stack);
// void    ft_ss(Stack *stackA, Stack *stackB);
// void    ft_ra(Stack *stack);
// void    ft_rb(Stack *stack);
// void    ft_rr(Stack *stackA, Stack *stackB);
// void    ft_rra(Stack *stack);
// void    ft_rrb(Stack *stack);
// void    ft_pa(Stack *stackA, Stack *stackB);
// void    ft_pb(Stack *stackA, Stack *stackB);
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