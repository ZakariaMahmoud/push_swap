#include "push_swap.h"

int get_min(t_stack *stack, int *position)
{
	int	min;
	int i;

	i = 0;
	min = stack->content;
	*position = 0;
	while(stack != NULL)
	{
		if(min > stack->content)
		{
			*position = i;
			min = stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (min);
}

void min_to_top(t_stack **stack, int size, int position)
{
	if(position <= (size - 1) / 2)
	{
		size = 0;
		while(size < position)
		{
			if (size + 1 < position)
			{
				ft_rr(stack, stack);
				size++;
			}
			else
				ft_ra(stack, 1);
			size++;
		}
	}
	else
	{
		while(size > position )
		{
			if(size - 1 > position)
			{
				ft_rrr(stack, stack);
				size--;
			}
			else
				ft_rra(stack, 1);
			size--;
		}
	}
}