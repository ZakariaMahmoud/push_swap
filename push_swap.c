#include "push_swap.h"

void	ft_check(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])) || (argv[i][j] == '+' && ft_isdigit(argv[i][j + 1]))))
			{
				write(1,"Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void ft_check_duplicated(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while(i < argc)
	{
		j = i + 1;
		while(j < argc)
		{
			if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1,"Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}

}

int is_sorted(t_stack *stack)
{
	int		check;

	check = stack->content;
	while (stack)
	{
		if(check > stack->content)
			return (0);
		else
			check = stack->content;
		stack = stack->next;
	}
	return (1); 	
}

void print_stack(t_stack *stack)
{
	printf("[");
	while (stack)
	{
		printf("%d, ", stack->content);
		stack = stack->next;
	}
	printf("\b\b]\n");
}

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
	int position;
	int size;
	t_stack *stack_b;
	t_stack *second;

	second = (*stack)->next;
	size = ft_lstsize(*stack);
	stack_b = NULL;
	if ((*stack)->content > second->content) ft_sa(*stack, 1);
	while(size > 3)
	{
		if(is_sorted(*stack)) break;
		get_min(*stack, &position);
		min_to_top(stack, size, position);
		ft_pb(stack, &stack_b);
		size--;
	}
	if(!is_sorted(*stack)) sort_three_numbers(stack);
	size = ft_lstsize(stack_b);
	while(size-- > 0)
		ft_pa(stack, &stack_b);
}

void sort_less_100(t_stack **stack, int capacity)
{
	int *array;
	int middle;

	array = malloc(capacity * sizeof(int));
	push_to_array(*stack, array, capacity);
	print_array(array, capacity);
	sort_array(array, capacity);
	print_array(array, capacity);
	if (capacity <= 150)
	{
		if(capacity % 2) middle = (capacity / 2) + 1;  
		else  middle = (capacity / 2);
		
	}
	free(array);
}

int main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	if (argc > 2)
	{
		ft_check(argc, argv);
		ft_check_duplicated(argc, argv);
		stack = ft_lstnew(ft_atoi(argv[1]));

		i = 2;
		while(i < argc)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i++])));
		if (!is_sorted(stack))
		{
			print_stack(stack);
			if (argc == 3)
				ft_sa(stack, 1);
			else if (argc == 4)
			 	sort_three_numbers(&stack);
			else if (argc < 10)
				sort_less_ten(&stack);
			else if (argc <= 100)
				sort_less_100(&stack, argc - 1);
			print_stack(stack);
		}
	}
	else if(argc == 2)
		ft_check(argc, argv);
}