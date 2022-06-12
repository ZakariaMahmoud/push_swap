/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:23:09 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/12 09:10:15 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_helper(t_helper *helper, int size)
{
	helper->array = malloc(size * sizeof(int));
	if (!helper->array)
		exit(0);
	helper->size = size;
	helper->middle = size / 2;
	helper->max = size - 1;
	helper->min = 0;
	helper->down = 0;
}
