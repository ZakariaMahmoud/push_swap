// #include "push_swap.h"

// void ft_sa(t_stack *stack, int print)
// {
// 	t_stack	*tmp_stack;
//     int n;

// 	if (!ft_lstsize(stack))
// 		return;
//     tmp_stack = stack->next;
//     n = tmp_stack->content;
//     tmp_stack->content = stack->content;
//     stack->content = n;
// 	if(print)
// 		write(1,"sa\n", 3);
// }

// void ft_sb(t_stack *stack, int print)
// {
// 	t_stack	*tmp_stack;
//     int n;

// 	if (!ft_lstsize(stack))
// 		return;
// 	tmp_stack = stack->next;
// 	n = tmp_stack->content;
// 	tmp_stack->content = stack->content;
// 	stack->content = n;
// 	if(print)
// 		write(1,"sb\n", 3);
// }

// void ft_ss(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (!ft_lstsize(stack_a) || !ft_lstsize(stack_b))
// 		return;
// 	ft_sa(stack_a, 0);
// 	ft_sb(stack_b, 0);
// 	write(1,"ss\n", 3);
// }

// void ft_rra(t_stack **stack)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;

// 	last = *stack;
// 	before_last = NULL;
// 	while(last != NULL && last->next != NULL)
// 	{
// 		before_last = last;
// 		last = last->next;
// 	}
// 	before_last->next = NULL;
// 	last->next = *stack;
// 	*stack = last;
// 	write(1,"rra\n", 4);
// }

// void ft_rrb(t_stack **stack)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;

// 	last = *stack;
// 	before_last = NULL;
// 	while(last != NULL && last->next != NULL)
// 	{
// 		before_last = last;
// 		last = last->next;
// 	}
// 	before_last->next = NULL;
// 	last->next = *stack;
// 	*stack = last;
// 	write(1,"rrb\n", 4);
// }

// void ft_rrr(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;

// 	last = *stack_a;
// 	before_last = NULL;
// 	while(last != NULL && last->next != NULL)
// 	{
// 		before_last = last;
// 		last = last->next;
// 	}
// 	before_last->next = NULL;
// 	last->next = *stack_a;
// 	*stack_a = last;

// 	last = *stack_b;
// 	before_last = NULL;
// 	while(last != NULL && last->next != NULL)
// 	{
// 		before_last = last;
// 		last = last->next;
// 	}
// 	before_last->next = NULL;
// 	last->next = *stack_b;
// 	*stack_b = last;
// 	write(1,"rrr\n", 4);
// }


// void ft_pa(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;
// 	t_stack *tmp;

// 	last = ft_lstlast(*stack_b);
// 	t_stack *tmp = *stack_a;
// 	if (stack_a != NULL)
// 		ft_lstadd_back(stack_a, ft_lstnew(ft_lstlast(*stack_b)->content));
// 	else
// 		tmp = ft_lstnew(5);

// 	before_last = NULL;
// 	last = *stack_b;
// 	while(last != NULL && last->next != NULL)
// 	{
// 		before_last = last;
// 		last = last->next;
// 	}
// 	before_last->next = NULL;
// 	free(last);

// 	write(1,"pa\n", 3);
// }

// void ft_pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;
// 	last = ft_lstlast(*stack_a);
	
// 	t_stack *tmp = *stack_b;
// 	if (stack_b != NULL)
// 		ft_lstadd_back(stack_b, ft_lstnew(ft_lstlast(*stack_a)->content));
// 	else
// 		tmp = ft_lstnew(5);

// 	before_last = NULL;
// 	last = *stack_a;
// 	while(last != NULL && last->next != NULL)
// 	{
// 		before_last = last;
// 		last = last->next;
// 	}
// 	before_last->next = NULL;
// 	free(last);

// 	write(1,"pb\n", 3);
// }