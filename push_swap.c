/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:15 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/17 18:06:50 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(int argc, t_stack **stack)
{
	if (argc == 2)
		ft_sa(*stack, 1);
	else if (argc == 3)
		sort_three_numbers(stack);
	else if (argc <= 10)
		sort_less_ten(stack);
	else
		big_sort(stack, argc);
}

static void	ft_free_args(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;
	char	**args;
	char	*args_str;

	args_str = args_to_str(argc, argv);
	args = ft_split(args_str, ' ');
	argc = arglen(args);
	if (argc <= 1)
		ft_check_args(argc, args);
	else if (argc > 1)
	{
		ft_check_args(argc, args);
		ft_check_duplicated(argc, args);
		stack = ft_lstnew(ft_atoi(args[0]));
		i = 1;
		while (i < argc)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(args[i++])));
		if (!is_sorted(stack))
			sort(argc, &stack);
	}
	else if (argc == 2)
		ft_check_args(argc, args);
	ft_free_args(args, argc);
}
