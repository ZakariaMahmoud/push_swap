/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:24 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/03 16:18:26 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_strdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	printf("sttr = %s\n", str);
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
		j = 0;
		while (argv[i][j])
		{
			check = is_strdigit(&argv[i][j + 1]);
			printf("check = %s | return = %d\n", &argv[i][j + 1], check);
			if (!(ft_isdigit(argv[i][j])
				|| (argv[i][j] == '-' && !check)
				|| (argv[i][j] == '+' && !check)))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
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
