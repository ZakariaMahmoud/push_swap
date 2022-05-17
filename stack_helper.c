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


void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
		
	}
}