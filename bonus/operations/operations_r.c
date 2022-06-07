/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:51:04 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 09:57:22 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **stack)
{
	t_stack	*top;

	if (!ft_lstsize(*stack))
		return ;
	top = *stack;
	ft_lstadd_back(stack, ft_lstnew(top->content));
	remove_top_stack(stack);
}

void	ft_rb(t_stack **stack)
{
	t_stack	*top;

	if (!ft_lstsize(*stack))
		return ;
	top = *stack;
	ft_lstadd_back(stack, ft_lstnew(top->content));
	remove_top_stack(stack);
}

void	ft_rra(t_stack **stack)
{
	if (!ft_lstsize(*stack))
		return ;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	remove_bottom_stack(stack);
}

void	ft_rrb(t_stack **stack)
{
	if (!ft_lstsize(*stack))
		return ;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	remove_bottom_stack(stack);
}

