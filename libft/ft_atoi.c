/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:58:15 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/06 11:31:03 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	ret;

	n = 1;
	ret = 0;
	i = ft_isspace(str);
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (((ret * 10) + str[i] - '0') / 10 != ret)
		{
			if (n == -1)
				return (0);
			return (-1);
		}
		ret = (ret * 10) + (str[i++] - '0');
	}
	return (ret * n);
}
