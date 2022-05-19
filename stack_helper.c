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

void min_to_top(t_stack **stack, int index, int position)
{
	if(position <= (index - 1) / 2)
	{
		index = 0;
		while(index <= position)
		{
			if (index + 1 <= position) 
			{
				ft_rr(stack, stack);
				index++;
			}
			else
				ft_ra(stack, 1);
			index++;
		}
	}
	else
	{
		while(index > position + 1)
		{
			if (index - 1 > position) 
			{
				ft_rrr(stack, stack);
				index--;
			}
			else
				ft_rra(stack, 1);
			index--;
		}
	}
}