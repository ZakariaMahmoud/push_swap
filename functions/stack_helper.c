/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:05:41 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 15:51:25 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, t_helper *helper)
{
	int		position;
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->content <= helper->array[helper->max]
			&& tmp->content >= helper->array[helper->min])
		{
			position = get_position(*stack_a, tmp->content);
			to_top_a(stack_a, position);
			ft_pb(stack_a, stack_b, 1);
			if ((*stack_b)->content < helper->array[helper->middle])
				ft_rb(stack_b, 1);
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
	}
}

void	push_b_to_a_helper(t_stack **stack_a, t_stack **stack_b,
	t_helper *helper, int position)
{
	if ((*stack_b)->content == helper->array[helper->size])
	{
		ft_pa(stack_a, stack_b, 1);
		helper->size--;
	}
	else
	{
		if (helper->down == 0
			|| (*stack_b)->content > ft_lstlast(*stack_a)->content)
		{
			ft_pa(stack_a, stack_b, 1);
			ft_ra(stack_a, 1);
			helper->down++;
		}
		else
		{
			if (position > helper->size / 2)
				ft_rrb(stack_b, 1);
			else
				ft_rb(stack_b, 1);
		}
	}
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b, t_helper *helper)
{
	int	position;

	helper->size = ft_lstsize(*stack_b) - 1;
	while (helper->size >= 0)
	{
		position = get_position(*stack_b, helper->array[helper->size]);
		if (position >= 0)
			push_b_to_a_helper(stack_a, stack_b, helper, position);
		else
		{
			ft_rra(stack_a, 1);
			helper->down--;
			helper->size--;
		}
	}
	while (helper->down-- > 0)
		ft_rra(stack_a, 1);
}

void	to_top_a(t_stack **stack, int position)
{
	int	size;

	size = ft_lstsize(*stack);
	if (position <= (size - 1) / 2)
	{
		size = 0;
		while (size++ < position)
			ft_ra(stack, 1);
	}
	else
	{
		while (size-- > position)
			ft_rra(stack, 1);
	}
}

void	to_top_b(t_stack **stack, int position)
{
	int	size;

	size = ft_lstsize(*stack);
	if (position <= (size - 1) / 2)
	{
		size = 0;
		while (size++ < position)
			ft_rb(stack, 1);
	}
	else
	{
		while (size-- > position)
			ft_rrb(stack, 1);
	}
}
