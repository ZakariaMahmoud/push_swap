#include "push_swap.h"



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
			if (argc == 3)
				ft_sa(stack, 1);
			else if (argc == 4)
			 	sort_three_numbers(&stack);
			else if (argc <= 11)
				sort_less_ten(&stack);
			else
				big_sort(&stack, argc - 1);
		}
	}
	else if(argc == 2)
		ft_check(argc, argv);
}