#include "push_swap.h"

void ft_sa(Stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
	write(1,"sa\n", 3);
}

void ft_sb(Stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
	write(1,"sb\n", 3);
}

void ft_ss(Stack *stackA, Stack *stackB)
{
    int	tmp;

	tmp = stackA->array[stackA->top];
	stackA->array[stackA->top] = stackA->array[stackA->top - 1];
	stackA->array[stackA->top - 1] = tmp;

    tmp = stackB->array[stackB->top];
	stackB->array[stackB->top] = stackB->array[stackB->top - 1];
	stackB->array[stackB->top - 1] = tmp;
	write(1,"ss\n", 3);
}



void ft_ra(Stack *stack)
{
	int	tmp;
	int	top;

	top = stack->top;
	tmp = stack->array[top];
	while(top >= 1)
	{
		stack->array[top] = stack->array[top -1];
		top--;
	}
	stack->array[top] = tmp;
	write(1,"ra\n", 3);
}

void ft_rb(Stack *stack)
{
	int	tmp;
	int	top;

	top = stack->top;
	tmp = stack->array[top];
	while(top >= 1)
	{
		stack->array[top] = stack->array[top -1];
		top--;
	}
	stack->array[top] = tmp;
	write(1,"rb\n", 3);
}

void ft_rr(Stack *stackA, Stack *stackB)
{
	int	tmp;
	int	top;

	top = stackA->top;
	tmp = stackA->array[top];
	while(top >= 1)
	{
		stackA->array[top] = stackA->array[top -1];
		top--;
	}
	stackA->array[top] = tmp;

    top = stackB->top;
	tmp = stackB->array[top];
	while(top >= 1)
	{
		stackB->array[top] = stackB->array[top -1];
		top--;
	}
	stackB->array[top] = tmp;
	write(1,"rr\n", 3);
}

void ft_rra(Stack *stack)
{
	int	tmp;
	int	top;
	int	i;

	top = stack->top;
	tmp = stack->array[0];
	i = 0;
	while(i < top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	write(1,"rra\n", 4);
}

void ft_rrb(Stack *stack)
{
	int	tmp;
	int	top;
	int	i;

	top = stack->top;
	tmp = stack->array[0];
	i = 0;
	while(i < top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	write(1,"rrb\n", 4);
}

void ft_pa(Stack *stackA, Stack *stackB)
{
	int	topB;

	topB = stackB->top - 1;
	push(stackA, stackB->array[topB]);
	write(1,"pa\n", 4);
}

void ft_pb(Stack *stackA, Stack *stackB)
{
	int	topA;

	topA = stackA->top - 1;
	push(stackB, stackA->array[topA]);
	write(1,"pb\n", 4);
}

