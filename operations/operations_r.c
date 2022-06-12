/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:51:04 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/11 21:03:49 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **stack, int print)
{
	t_stack	*top;

	if (!ft_lstsize(*stack))
		return ;
	top = *stack;
	ft_lstadd_back(stack, ft_lstnew(top->content));
	remove_top_stack(stack);
	if (print)
		write(1, "ra\n", 3);
	print_stack(*stack, NULL, 1);
}

void	ft_rb(t_stack **stack, int print)
{
	t_stack	*top;

	if (!ft_lstsize(*stack))
		return ;
	top = *stack;
	ft_lstadd_back(stack, ft_lstnew(top->content));
	remove_top_stack(stack);
	if (print)
		write(1, "rb\n", 3);
	print_stack(NULL, *stack, 1);
}

void	ft_rra(t_stack **stack, int print)
{
	if (!ft_lstsize(*stack))
		return ;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	remove_bottom_stack(stack);
	if (print)
		write(1, "rra\n", 4);
	print_stack(*stack, NULL, 1);
}

void	ft_rrb(t_stack **stack, int print)
{
	if (!ft_lstsize(*stack))
		return ;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	remove_bottom_stack(stack);
	if (print)
		write(1, "rrb\n", 4);
	print_stack(NULL, *stack, 1);
}
