/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:10:34 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/10 15:20:34 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	arglen(char *args[])
{
	int		i;
	int		j;
	int		len;
	char	**split;

	i = 0;
	len = 0;
	while (args[i] != NULL)
	{
		j = 0;
		split = ft_split(args[i], ' ');
		while (split[j] != NULL)
		{
			free(split[j++]);
			len++;
		}
		free(split);
		i++;
	}
	return (len);
}

char	*args_to_str(int argc, char *argv[])
{
	char	*str;
	char	*space;
	int		i;

	str = ft_strdup(argv[1]);
	space = " ";
	i = 2;
	while (i < argc)
	{
		str = ft_strjoin(&str, &space);
		str = ft_strjoin(&str, &argv[i]);
		i++;
	}
	return (str);
}
