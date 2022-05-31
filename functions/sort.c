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

void sort_less_ten(t_stack **stack_a)
{
	t_stack *stack_b;
	t_stack *second;
	int     size;

	second = (*stack_a)->next;
	size = ft_lstsize(*stack_a);
	stack_b = NULL;
	if ((*stack_a)->content > second->content) ft_sa(*stack_a, 1);
	while(size > 3)
	{
		if(is_sorted(*stack_a)) break;
		to_top_a(stack_a, get_min_position(*stack_a));
		ft_pb(stack_a, &stack_b);
		size--;
	}
	if(!is_sorted(*stack_a)) sort_three_numbers(stack_a);
	size = ft_lstsize(stack_b);
	while(size-- > 0)
		ft_pa(stack_a, &stack_b);
}

void big_sort(t_stack **stack_a, int size)
{
	t_stack *stack_b;
	int *array;
	int	i;
	int offset;

	stack_b = NULL;
	i  = 1;
	array = malloc(size * sizeof(int));
	sort_array(*stack_a, array, size);
	offset = size / ((size <= 150) * 8 + (size > 150) * 18);
	while (size > 0)
	{
		if((size / 2) + (offset * i) >= size || (size / 2) - (offset * i) < 0)
		{
			push_a_to_b(stack_a, &stack_b, size - 1, 0, (size / 2),  array);
			break;
		}
		push_a_to_b(stack_a, &stack_b, (size / 2) + (offset * i), (size / 2) - (offset * i), (size / 2),  array);
		i++;
	}
	push_b_to_a(stack_a, &stack_b, array);
	free(array);
}
