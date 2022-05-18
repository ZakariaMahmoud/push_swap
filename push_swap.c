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



void sort_three_numbers(t_stack **stack)
{
	t_stack *second;
	t_stack *last;

	second = (*stack)->next;
	last = ft_lstlast(*stack);
	if((*stack)->content > second->content) 
	{
		if(second->content < last->content && (*stack)->content < last->content) ft_sa(*stack);
		else if (second->content > last->content)
		{
			ft_sa(*stack);
			ft_rra(stack);
		}
		else if (second->content < last->content) ft_ra(stack);
	}
	else
	{
		if((*stack)->content > last->content) ft_rra(stack);
		else
		{
			ft_sa(*stack);
			ft_ra(stack);
		}
	}
}

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
			if (argc == 3)
				ft_sa(stack);
			else if (argc == 4)
			 	sort_three_numbers(&stack);
			print_stack(stack);
		}
	}
	else if(argc == 2)
		ft_check(argc, argv);
}

// TWO STACK
// int main()
// {
// 	t_stack *stackA;
// 	t_stack *stackB;


// 	stackA = ft_lstnew(0);
// 	ft_lstadd_back(&stackA, ft_lstnew(1));
// 	ft_lstadd_back(&stackA, ft_lstnew(2));
// 	ft_lstadd_back(&stackA, ft_lstnew(3));
// 	printf("\n--- Stack A ---\n");
// 	print_stack(stackA);
// 	printf("---------------\n");
// 	stackB = ft_lstnew(4);
// 	ft_lstadd_back(&stackB, ft_lstnew(5));
// 	ft_lstadd_back(&stackB, ft_lstnew(6));
// 	ft_lstadd_back(&stackB, ft_lstnew(7));
// 	printf("\n--- Stack B ---\n");
// 	print_stack(stackB);
// 	printf("---------------\n");

// 	printf("\n---------- Traitement -----------\n");
// 	ft_pb(&stackA, &stackB);
// 	printf("\n--- Stack A ---\n");
// 	print_stack(stackA);
// 	printf("---------------\n");
// 	printf("\n--- Stack B ---\n");
// 	print_stack(stackB);
// 	printf("---------------\n");

// }	

// int main(int argc, char *argv[])
// {
// 	int		i;
// 	t_stack	*stack;

// 	if (argc > 2)
// 	{
// 		ft_check(argc, argv);
// 		ft_check_duplicated(argc, argv);
// 		stack = ft_lstnew(ft_atoi(argv[1]));

// 		i = 2;
// 		while(i < argc)
// 			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i++])));
			
// 		if (!is_sorted(stack))
// 		{
// 			print_stack(stack);
// 			ft_sa(stack);
// 			print_stack(stack);

// 			ft_rra(&stack);
// 			// if (argc == 3)
// 			// 	ft_sa(stack);
// 			// else if (argc == 4)
// 			//  	sort_three_numbers(stack);
// 			print_stack(stack);
// 		}
// 	}
// 	else if(argc == 2)
// 		ft_check(argc, argv);
// }