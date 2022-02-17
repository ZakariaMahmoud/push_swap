/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:32:19 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/11 22:53:55 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*y;
	unsigned char	*str;

	i = 0;
	y = NULL;
	str = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == str[i])
			return (&str[i]);
		i++;
	}
	return (y);
}
