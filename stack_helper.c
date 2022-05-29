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

void print_array(int *array, int capacity)
{
	int	i;

	i = 0;
	printf("Array [");
	while (i < capacity)
		printf("%d, ", array[i++]);
	printf("\b\b]\n");
}
void push_to_array(t_stack *stack, int *array, int capacity)
{
	int	i;

	i = 0;
	while(i < capacity && stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
}

void sort_array(int *array, int capacity)
{
	int i;
	int j;
	int	tmp;

	i = 0;
	while(i < capacity)
	{
		j = 0;
		while (j < capacity)
		{
			if(j > 0 && array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void push_to_b(t_stack **stack_a, t_stack **stack_b, int max, int min, int middle, int *array)
{

	printf("Middle = %d\n", middle);
	while(min <= max)
	{
		to_top(stack_a, get_position(*stack_a, array[min]));
		ft_pb(stack_a, stack_b);
		if (ft_after_head(stack_b) && ft_after_head(stack_b)->content > (*stack_b)->content)
			ft_rb(stack_b, 1);
		print_stack(*stack_b, "Stack B");
	}
}

int in_range(t_stack *stack, int max, int min)
{
	int i;
	int position;

	i = 0;
	position = -1;
	while(stack != NULL)
	{
		if(stack->content <= max && stack->content >= min)
		{
			position = i;
			break;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

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

void to_top(t_stack **stack, int position)
{
	int size;

	size = ft_lstsize(*stack);
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