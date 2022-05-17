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

Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int is_sorted(Stack *stack)
{
	int	i;

	i = stack->top;
	while(i >= 0)
	{
		if (i - 1 >= 0 && stack->array[i] > stack->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}
void push(Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}



void sort_three_numbers(Stack *stack)
{
	int	top;

	top = stack->top;
	if (stack->array[top] > stack->array[top - 1] && stack->array[top - 1] > stack->array[top - 2])
	{
		ft_ra(stack);
		ft_sa(stack);
	}
	else if (stack->array[top] > stack->array[top - 1] && stack->array[top - 1] < stack->array[top - 2])
	{
		if (stack->array[top] > stack->array[top - 2] )
			ft_ra(stack);
		else if (stack->array[top] < stack->array[top - 2])
			ft_sa(stack);

	}
	else if (stack->array[top] < stack->array[top - 1] && stack->array[top - 1] > stack->array[top - 2])
	{
		if (stack->array[top] > stack->array[top - 2] )
			ft_rra(stack);
		else if (stack->array[top] < stack->array[top - 2])
		{
			ft_sa(stack);
			ft_ra(stack);
		}
	}
	else if (stack->array[top] > stack->array[top - 1] && stack->array[top - 1] < stack->array[top - 2])
		ft_rra(stack);

}

void print_stack(Stack *stack)
{
	int top;

	top = stack->top;
	while(top >= 0)
	{
		printf("Array[%d] = %d\n", top, stack->array[top]);
		top--;
	}

}

int main(int argc, char *argv[])
{
	int	i;
	Stack	*stack;

	i = 1;
	if (argc > 2)
	{

		ft_check(argc, argv);
		ft_check_duplicated(argc, argv);
		i = argc - 1;
		stack = createStack(argc - 1);
		while(i > 0)
			push(stack, ft_atoi(argv[i--]));
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

// 3 2 1
// 2 3 1
// 3 1 2

// sa  = 2 3 1
// rra = 1 2 3 


// print_stack(stack);
// 			ft_rra(stack);
// 			print_stack(stack);

