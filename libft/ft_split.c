/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:22:29 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/12 09:27:39 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_countword(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{	
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			word++;
		i++;
	}
	return (word);
}

static int	ft_charlen(const char *s, char c, int *start)
{
	int	i;
	int	len;

	i = *start;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	*start = i;
	return (len);
}

static char	**ft_free_split(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		word;
	int		len;
	int		start;
	int		i;

	if (!s)
		return (0);
	word = ft_countword(s, c);
	ret = (char **)malloc((word + 1) * sizeof(char *));
	if (!ret)
		return (0);
		i = 0;
	start = 0;
	while (i < word)
	{
		len = ft_charlen(s, c, &start);
		ret[i] = ft_substr(s, start - len, len);
		if (!ret[i])
			return (ft_free_split(ret, i));
		i++;
	}
	ret[i] = 0;
	return (ret);
}
