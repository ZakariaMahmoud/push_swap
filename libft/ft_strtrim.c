/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:31:02 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/12 01:55:56 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_search(char const *str, char c)
{
	while (*str)
	{	
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!str)
		return (0);
	if (!set)
		return ((char *)str);
	j = ft_strlen(str);
	while (ft_search(set, str[i]))
		i++;
	while (ft_search(set, str[j - 1]) && j > i)
		j--;
	ret = (char *)malloc((j - i + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, str + i, j - i + 1);
	return (ret);
}
