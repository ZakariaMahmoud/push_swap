/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:51:06 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 09:58:04 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		n;

	if (!ft_lstsize(stack))
		return ;
	tmp_stack = stack->next;
	n = tmp_stack->content;
	tmp_stack->content = stack->content;
	stack->content = n;
}

void	ft_sb(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		n;

	if (!ft_lstsize(stack))
		return ;
	tmp_stack = stack->next;
	n = tmp_stack->content;
	tmp_stack->content = stack->content;
	stack->content = n;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_lstsize(stack_a) || !ft_lstsize(stack_b))
		return ;
	ft_sa(stack_a);
	ft_sb(stack_b);
}
