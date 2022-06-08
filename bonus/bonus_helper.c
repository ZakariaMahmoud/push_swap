/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:56:55 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/08 11:16:25 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		check;

	check = stack->content;
	while (stack)
	{
		if (check > stack->content)
			return (0);
		else
			check = stack->content;
		stack = stack->next;
	}
	return (1);
}
