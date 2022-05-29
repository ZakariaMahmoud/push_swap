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
		while(size++ < position)
			ft_ra(stack, 1);
	}
	else
	{
		while(size-- > position )
			ft_rra(stack, 1);
	}
}

void print_array(int *array, int capacity)
{
	int	i;

	i = 0;
	printf("Array [");
	while (i < capacity)
	{
		printf("{%d} %d, ",i, array[i]);
		i++;
	}
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

void push_a_to_b(t_stack **stack_a, t_stack **stack_b, int max, int min,int middle,  int *array)
{
	t_stack *tmp;
	tmp = *stack_a;
	int position;
	while(tmp != NULL)
	{
		position = get_position(*stack_a, tmp->content);
	
		if(tmp->content <= array[max] && tmp->content >= array[min])
		{
			// printf("tmp->content = %d | array[max]  = %d | array[min] = %d \n",tmp->content, array[max], array[min]);
			to_top_a(stack_a, position);
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->content < middle)
				ft_rb(stack_b, 1);
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
	}
	// print_stack(*stack_b, "******** Stack B ********");
}

void push_b_to_a(t_stack **stack_a, t_stack **stack_b, int *array)
{
	int size;
	int	down;
	int position;

	down = 0;
	size = ft_lstsize(*stack_b) - 1;
	// print_stack(*stack_a, "Stack A");
	// print_stack(*stack_b, "Stack B");
	while(size >= 0)
	{
		// printf("---- size = %d ---\n", size);
		
		position = get_position(*stack_b, array[size]);
		// printf("array[size] = %d | position = %d\n", array[size], position);
		if(position >= 0)
		{
			if((*stack_b)->content == array[size])
			{
				ft_pa(stack_a, stack_b);
				size--;
			}
			else
			{
				if (down == 0 || (*stack_b)->content > ft_lstlast(*stack_a)->content)
				{
					ft_pa(stack_a, stack_b);
					ft_ra(stack_a, 1);
					down++;
				}
				else
				{
					if (position > size / 2)
						ft_rrb(stack_b, 1);
					else
						ft_rb(stack_b, 1);
				}
			}
		}
		else 
		{
			ft_rra(stack_a, 1);
			down--;
			size--;
		}
		
		
	}
	while(down-- > 0)
		ft_rra(stack_a, 1);
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

void to_top_a(t_stack **stack, int position)
{
	int size;

	size = ft_lstsize(*stack);
	if(position <= (size - 1) / 2)
	{
		size = 0;
		while(size++ < position)
			ft_ra(stack, 1);
	}
	else
	{
		while(size-- > position)
			ft_rra(stack, 1);
	}
}

void to_top_b(t_stack **stack, int position)
{
	int size;

	size = ft_lstsize(*stack);
	if(position <= (size - 1) / 2)
	{
		size = 0;
		while(size++ < position)
			ft_rb(stack, 1);
	}
	else
	{
		while(size-- > position)
			ft_rrb(stack, 1);
	}
}