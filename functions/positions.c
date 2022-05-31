#include "../push_swap.h"

int get_position(t_stack *stack, int value)
{
	int i;
	int position;

	i = 0;
	position = -1;
	while(stack != NULL)
	{
		if(stack->content == value)
		{
			position = i;
			break;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

int get_min_position(t_stack *stack)
{
	int	min;
	int i;
    int position;

	i = 0;
	min = stack->content;
	position = 0;
	while(stack != NULL)
	{
		if(min > stack->content)
		{
			position = i;
			min = stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}