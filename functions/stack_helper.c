#include "../push_swap.h"

void push_a_to_b(t_stack **stack_a, t_stack **stack_b, int max, int min,int middle,  int *array)
{
	t_stack *tmp;
	tmp = *stack_a;
	int position;
	while(tmp != NULL)
	{
		if(tmp->content <= array[max] && tmp->content >= array[min])
		{
			position = get_position(*stack_a, tmp->content);
			to_top_a(stack_a, position);
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->content < array[middle])
				ft_rb(stack_b, 1);
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
	}
}

void push_b_to_a(t_stack **stack_a, t_stack **stack_b, int *array)
{
	int size;
	int	down;
	int position;

	down = 0;
	size = ft_lstsize(*stack_b) - 1;
	while(size >= 0)
	{
		position = get_position(*stack_b, array[size]);
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

