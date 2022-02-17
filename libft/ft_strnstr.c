/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:33:14 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/26 14:17:29 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *need, size_t len)
{
	size_t	i;
	size_t	n_size;	

	i = 0;
	n_size = ft_strlen(need);
	if (!n_size)
		return ((char *)str);
	while (i < len && str[i])
	{
		if (ft_strncmp(&str[i], need, n_size) == 0
			&& n_size + i <= len)
			return ((char *) &str[i]);
		i++;
	}
	return (NULL);
}
