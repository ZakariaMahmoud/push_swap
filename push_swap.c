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
		if(check < stack->content)
			return (0);
		else
			check = stack->content;
		stack = stack->next;
	}
	return (1); 	
}
// void push(Stack *stack, int item)
// {
//     stack->array[++stack->top] = item;
// }



// void sort_three_numbers(Stack *stack)
// {
// 	int	top;

// 	top = stack->top;
// 	if (stack->array[top] > stack->array[top - 1] && stack->array[top - 1] > stack->array[top - 2])
// 	{
// 		ft_ra(stack);
// 		ft_sa(stack);
// 	}
// 	else if (stack->array[top] > stack->array[top - 1] && stack->array[top - 1] < stack->array[top - 2])
// 	{
// 		if (stack->array[top] > stack->array[top - 2] )
// 			ft_ra(stack);
// 		else if (stack->array[top] < stack->array[top - 2])
// 			ft_sa(stack);

// 	}
// 	else if (stack->array[top] < stack->array[top - 1] && stack->array[top - 1] > stack->array[top - 2])
// 	{
// 		if (stack->array[top] > stack->array[top - 2] )
// 			ft_rra(stack);
// 		else if (stack->array[top] < stack->array[top - 2])
// 		{
// 			ft_sa(stack);
// 			ft_ra(stack);
// 		}
// 	}
// 	else if (stack->array[top] > stack->array[top - 1] && stack->array[top - 1] < stack->array[top - 2])
// 		ft_rra(stack);

// }

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("--[%d]\n", stack->content);
		stack = stack->next;
	}
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

		i = argc - 1;
		while(i > 1)
		{	
			ft_lstadd_front(&stack, ft_lstnew(ft_atoi(argv[i])));
			i--;
		}
			
		if (!is_sorted(stack))
		{
			print_stack(stack);
			if (argc == 3)
				ft_sa(stack);
			else if (argc == 4)
			 	sort_three_numbers(stack);
			print_stack(stack);
		}
	}
	else if(argc == 2)
		ft_check(argc, argv);
}
