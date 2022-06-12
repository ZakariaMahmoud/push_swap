/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:51:06 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/12 09:07:05 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *stack, int print)
{
	t_stack	*tmp_stack;
	int		n;

	if (!ft_lstsize(stack))
		return ;
	tmp_stack = stack->next;
	n = tmp_stack->content;
	tmp_stack->content = stack->content;
	stack->content = n;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack, int print)
{
	t_stack	*tmp_stack;
	int		n;

	if (!ft_lstsize(stack))
		return ;
	tmp_stack = stack->next;
	n = tmp_stack->content;
	tmp_stack->content = stack->content;
	stack->content = n;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (!ft_lstsize(stack_a) || !ft_lstsize(stack_b))
		return ;
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (print)
		write(1, "ss\n", 3);
}
