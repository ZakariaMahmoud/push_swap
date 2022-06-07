/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:51:04 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 09:58:28 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_lstsize(*stack_a) || !ft_lstsize(*stack_b))
		return ;
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
