/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:59 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/11 21:04:41 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*top;

	top = *stack_b;
	if (!ft_lstsize(*stack_b))
		return ;
	if (ft_lstsize(*stack_a))
		ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
	else
		*stack_a = ft_lstnew(top->content);
	remove_top_stack(stack_b);
	if (print)
		write(1, "pa\n", 3);
	print_stack(*stack_a, *stack_b, 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*top;

	top = *stack_a;
	if (!ft_lstsize(*stack_a))
		return ;
	if (ft_lstsize(*stack_b))
		ft_lstadd_front(stack_b, ft_lstnew(top->content));
	else
		*stack_b = ft_lstnew(top->content);
	remove_top_stack(stack_a);
	if (print)
		write(1, "pb\n", 3);
	print_stack(*stack_a, *stack_b, 1);
}
