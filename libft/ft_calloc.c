/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:31:55 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/26 16:02:19 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	ptr = (void *)malloc (count * size);
	if (!ptr)
		return (0);
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}
