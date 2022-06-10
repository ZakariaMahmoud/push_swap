/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:32:47 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/10 08:27:56 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*p;

	size = ft_strlen(s1);
	p = (char *)malloc ((size + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s1, size);
	p[size] = '\0';
	return ((char *)p);
}
