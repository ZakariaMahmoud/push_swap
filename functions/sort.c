#include "../push_swap.h"

void sort_three_numbers(t_stack **stack)
{
	t_stack *second;
	t_stack *last;

	second = (*stack)->next;
	last = ft_lstlast(*stack);
	if((*stack)->content > second->content) 
	{
		if(second->content < last->content && (*stack)->content < last->content) ft_sa(*stack, 1);
		else if (second->content > last->content)
		{
			ft_sa(*stack, 1);
			ft_rra(stack, 1);
		}
		else if (second->content < last->content) ft_ra(stack, 1);
	}
	else
	{
		if((*stack)->content > last->content) ft_rra(stack, 1);
		else
		{
			ft_sa(*stack, 1);
			ft_ra(stack, 1);
		}
	}
}

void sort_less_ten(t_stack **stack)
{
	t_stack *stack_b;
	t_stack *second;
	int     size;

	second = (*stack)->next;
	size = ft_lstsize(*stack);
	stack_b = NULL;
	if ((*stack)->content > second->content) ft_sa(*stack, 1);
	while(size > 3)
	{
		if(is_sorted(*stack)) break;
		to_top_a(stack, get_min_position(*stack));
		ft_pb(stack, &stack_b);
		size--;
	}
	if(!is_sorted(*stack)) sort_three_numbers(stack);
	size = ft_lstsize(stack_b);
	while(size-- > 0)
		ft_pa(stack, &stack_b);
}

void big_sort(t_stack **stack, int size)
{
	t_stack *stack_b;
	int *array;
	int middle;
	int	i;
	int min;
	int max;
	int offset;

	stack_b = NULL;
	array = malloc(size * sizeof(int));
	sort_array(*stack, array, size);

	i  = 1;
	middle = size / 2;  
	offset = size / ((size <= 150) * 8 + (size > 150) * 18);
	while (size > 0)
	{
		max = middle + (offset * i);
		min = middle - (offset * i);
		if(max >= size || min < 0)
		{
			min = 0;
			max = size - 1;
			size = -1;
		}
		push_a_to_b(stack, &stack_b, max, min,middle,  array);
		i++;
	}
	push_b_to_a(stack, &stack_b, array);
	free(array);
}
