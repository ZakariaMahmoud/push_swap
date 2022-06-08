/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:24 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/08 09:07:50 by zmahmoud         ###   ########.fr       */
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

void	ft_check_args(int argc, char *argv[])
{
	int	i;
	int	j;
	int	check;	

	i = 1;
	while (i < argc)
	{
		if (!(is_strdigit(argv[i])
				|| (argv[i][0] == '-' && is_strdigit(&argv[i][1]))
				|| (argv[i][0] == '+' && is_strdigit(&argv[i][1]))))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	ft_check_int_range(argc, argv);
}

void	ft_check_int_range(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

void	ft_check_duplicated(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
