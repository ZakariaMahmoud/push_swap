/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:39:04 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/10 15:20:37 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
	return (NULL);
}

char	*ft_strjoin(char **s1, char **s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	if (!*s1 || !*s2)
		return (NULL);
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(*s2);
	ret = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, *s1, s1_len);
	ft_memcpy(ret + s1_len, *s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	ft_free(s1);
	return (ret);
}
