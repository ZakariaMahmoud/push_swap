#include "push_swap.h"


t_stack	*ft_lstnew(int	content)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int get_min(t_stack *stack, int *index, int *position)
{
	int	min;

	index = 0;
	min = stack->content;
	position = 0;
	while(stack != NULL)
	{
		if(min > stack->content)
		{
			position = index;
			min = stack->content;
		}
		stack = stack->next;
		index++;
	}
	return (min);
}