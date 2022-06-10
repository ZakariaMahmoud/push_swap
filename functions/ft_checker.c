/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:24 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/10 15:15:32 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_strdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

void	ft_check_args(int argc, char *args[])
{
	int	i;	

	i = 0;
	while (i < argc)
	{
		if (!(is_strdigit(args[i])
				|| (args[i][0] == '-' && is_strdigit(&args[i][1]))
				|| (args[i][0] == '+' && is_strdigit(&args[i][1]))))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	ft_check_int_range(argc, args);
}

void	ft_check_int_range(int argc, char *args[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

void	ft_check_duplicated(int argc, char *args[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
