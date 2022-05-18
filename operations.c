#include "push_swap.h"

void ft_sa(t_stack *stack)
{
	t_stack	*tmp_stack;
    int n;

    tmp_stack = stack->next;
    n = tmp_stack->content;
    tmp_stack->content = stack->content;
    stack->content = n;
	write(1,"sa\n", 3);
}

void ft_sb(t_stack *stack)
{
	t_stack	*tmp_stack;
    int n;

	tmp_stack = stack->next;
	n = tmp_stack->content;
	tmp_stack->content = stack->content;
	stack->content = n;
	write(1,"sb\n", 3);
}



void ft_ss(t_stack *stackA, t_stack *stackB)
{
    t_stack	*tmp_stack;
    int n;

	tmp_stack = stackA->next;
    n = tmp_stack->content;
    tmp_stack->content = stackA->content;
    stackA->content = n;

    tmp_stack = stackB->next;
    n = tmp_stack->content;
    tmp_stack->content = stackB->content;
    stackB->content = n;
	write(1,"ss\n", 3);
}

void ft_rra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	last = *stack;
	before_last = NULL;
	while(last != NULL && last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1,"rra\n", 4);
}

void ft_rrb(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	last = *stack;
	before_last = NULL;
	while(last != NULL && last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1,"rrb\n", 4);
}

void ft_rrr(t_stack **stackA, t_stack **stackB)
{
	t_stack	*last;
	t_stack	*before_last;

	last = *stackA;
	before_last = NULL;
	while(last != NULL && last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stackA;
	*stackA = last;

	last = *stackB;
	before_last = NULL;
	while(last != NULL && last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stackB;
	*stackB = last;
	write(1,"rrr\n", 4);
}

 void ft_ra(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*after_head;

	head = *stack;
	after_head = head->next;
	last = ft_lstlast(*stack);
	last->next = head;
	*stack = after_head;
	head->next = NULL;
	write(1,"ra\n", 3);
}

 void ft_rb(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*after_head;

	head = *stack;
	after_head = head->next;
	last = ft_lstlast(*stack);
	last->next = head;
	*stack = after_head;
	head->next = NULL;
	write(1,"rb\n", 3);
}

void ft_rr(t_stack **stackA, t_stack **stackB)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*after_head;

	head = *stackA;
	after_head = head->next;
	last = ft_lstlast(*stackA);
	last->next = head;
	*stackA = after_head;
	head->next = NULL;

	head = *stackB;
	after_head = head->next;
	last = ft_lstlast(*stackB);
	last->next = head;
	*stackB = after_head;
	head->next = NULL;

	write(1,"rr\n", 3);
}

void ft_pa(t_stack **stackA, t_stack **stackB)
{
	t_stack	*last;
	t_stack	*before_last;

	last = ft_lstlast(*stackB);
	ft_lstadd_back(stackA, ft_lstnew(ft_lstlast(*stackB)->content));

	before_last = NULL;
	last = *stackB;
	while(last != NULL && last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	free(last);

	write(1,"pa\n", 3);
}

void ft_pb(t_stack **stackA, t_stack **stackB)
{
	t_stack	*last;
	t_stack	*before_last;

	last = ft_lstlast(*stackA);
	ft_lstadd_back(stackB, ft_lstnew(ft_lstlast(*stackA)->content));

	before_last = NULL;
	last = *stackA;
	while(last != NULL && last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	free(last);

	write(1,"pb\n", 3);
}