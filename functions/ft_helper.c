#include "../push_swap.h"

t_stack *ft_before_last(t_stack **stack)
{
    t_stack *tmp;
    t_stack *before_last;

    tmp = *stack;
    before_last = *stack;
    if (!ft_lstlast(tmp)) return NULL;
    while(tmp != NULL && tmp->next != NULL)
    {
        before_last = tmp;
        tmp = tmp->next;
    }
    return (before_last);
}

t_stack *ft_after_head(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    if (!ft_lstlast(tmp)) return NULL;
    tmp = tmp->next;
    return (tmp);
}
void remove_bottom_stack(t_stack **stack)
{
    t_stack	*top;

    top = ft_lstlast(*stack);
    ft_before_last(stack)->next = NULL;
    free(top);
}

void    remove_top_stack(t_stack **stack)
{
    t_stack	*tmp;

    tmp = *stack;
    *stack = tmp->next;
    tmp->next = NULL;
    free(tmp);
}