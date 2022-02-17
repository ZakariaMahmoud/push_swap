/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:28:46 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/10 12:58:25 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if ((unsigned char)c == str[i])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
