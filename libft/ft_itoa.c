/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:27:39 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:09 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	int		i;

	i = 0;
	len = ft_intlen(n);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		ret[0] = '0';
	ret[len--] = '\0';
	while (n > 0)
	{
		ret[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
