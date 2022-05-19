#include "../push_swap.h"

void ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *top;

	top = *stack_b;
	if (ft_lstsize(*stack_a))
		ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
	else
		*stack_a = ft_lstnew(top->content);

	remove_top_stack(stack_b);
	write(1,"pa\n", 3);
}

void ft_pb(t_stack **stack_a, t_stack **stack_b)
{

	t_stack *top;

	top = *stack_a;
	if (ft_lstsize(*stack_b))
		ft_lstadd_front(stack_b, ft_lstnew(top->content));
	else
		*stack_b = ft_lstnew(top->content);

	remove_top_stack(stack_a);
	write(1,"pb\n", 3);
}