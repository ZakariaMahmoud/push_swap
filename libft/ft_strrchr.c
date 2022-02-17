/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:33:18 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/10 13:08:04 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		k;
	char	*y;

	i = 0;
	y = 0;
	k = -1;
	if ((unsigned char)c == 0)
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if ((unsigned char)c == str[i])
			k = i;
		i++;
	}	
	if (k > -1)
		y = (char *)&str[k];
	return (y);
}
