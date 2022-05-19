// C program for array implementation of stack
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
// void push(Stack *stack, int item)
// {
//     stack->array[++stack->top] = item;
// }


void print_stack(t_stack *stack)
{
	printf("HEAD [");
	while (stack)
	{
		printf("%d, ", stack->content);
		stack = stack->next;
	}
	printf("\b\b] TOP\n");
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
			ft_pa(&stack, &stack);
			print_stack(stack);
		}
	}
	else if(argc == 2)
		ft_check(argc, argv);
}

// int main()
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;


// 	stack_a = ft_lstnew(0);
//     stack_b = NULL;
// 	ft_lstadd_back(&stack_a, ft_lstnew(1));
// 	ft_lstadd_back(&stack_a, ft_lstnew(2));
// 	ft_lstadd_back(&stack_a, ft_lstnew(3));
// 	printf("\n--- Stack A ---\n");
// 	print_stack(stack_a);
// 	printf("---------------\n");
// 	stack_b = ft_lstnew(4);
// 	ft_lstadd_back(&stack_b, ft_lstnew(5));
// 	ft_lstadd_back(&stack_b, ft_lstnew(6));
// 	ft_lstadd_back(&stack_b, ft_lstnew(7));
// 	printf("\n--- Stack B ---\n");
// 	print_stack(stack_b);
// 	printf("---------------\n");

// 	printf("\n---------- Traitement -----------\n");
// 	ft_pb(&stack_a, &stack_b);
// 	ft_pb(&stack_a, &stack_b);
// 	printf("\n--- Stack A ---\n");
// 	print_stack(stack_a);
// 	printf("---------------\n");
// 	printf("\n--- Stack B ---\n");
// 	print_stack(stack_b);
// 	printf("---------------\n");

// }