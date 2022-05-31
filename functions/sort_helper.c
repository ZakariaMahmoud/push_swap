
#include "../push_swap.h"

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

void sort_array(t_stack *stack, int *array, int size)
{
	int i;
	int j;
	int	tmp;

	i = 0;
    while(i < size && stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
    i = 0;
	while(i < size)
	{
		j = 0;
		while (j < size)
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