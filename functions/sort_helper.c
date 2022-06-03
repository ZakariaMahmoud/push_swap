/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:06:55 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/03 13:09:18 by zmahmoud         ###   ########.fr       */
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

static void	push_to_array(t_stack *stack, t_helper *helper)
{
	int	i;

	i = 0;
	while (i < helper->size && stack)
	{
		helper->array[i] = stack->content;
		stack = stack->next;
		i++;
	}
}

void	sort_array(t_stack *stack, t_helper *helper)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	push_to_array(stack, helper);
	while (i < helper->size)
	{
		j = 0;
		while (j < helper->size)
		{
			if (j > 0 && helper->array[j] < helper->array[j - 1])
			{
				tmp = helper->array[j];
				helper->array[j] = helper->array[j - 1];
				helper->array[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
