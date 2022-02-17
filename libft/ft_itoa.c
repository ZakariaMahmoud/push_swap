/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:27:39 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/15 01:31:43 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
