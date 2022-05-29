#include "../push_swap.h"

void ft_ra(t_stack **stack, int print)
{
	t_stack	*top;

	if(!ft_lstsize(*stack)) return;
	top = *stack;
    ft_lstadd_back(stack, ft_lstnew(top->content));
    remove_top_stack(stack);
    if (print)
	    write(1,"ra\n", 3);
}

void ft_rb(t_stack **stack, int print)
{
	t_stack	*top;

	if(!ft_lstsize(*stack)) return;
	top = *stack;
    ft_lstadd_back(stack, ft_lstnew(top->content));
	remove_top_stack(stack);
    if (print)
	    write(1,"rb\n", 3);
}


void ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write(1,"rr\n", 3);
}



void ft_rra(t_stack **stack, int print)
{
	if(!ft_lstsize(*stack)) return;
    ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	remove_bottom_stack(stack);
    if (print)
	    write(1,"rra\n", 4);
}

void ft_rrb(t_stack **stack, int print)
{

	if(!ft_lstsize(*stack)) return;
    ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	remove_bottom_stack(stack);
    if (print)
	    write(1,"rrb\n", 4);
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_lstsize(*stack_a) || !ft_lstsize(*stack_b))
		return;
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1,"rrr\n", 4);
}
