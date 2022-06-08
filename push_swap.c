/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:50:15 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/08 11:35:46 by zmahmoud         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	if (argc > 2)
	{
		ft_check_args(argc, argv);
		ft_check_duplicated(argc, argv);
		stack = ft_lstnew(ft_atoi(argv[1]));
		i = 2;
		while (i < argc)
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i++])));
		if (!is_sorted(stack))
			sort(argc - 1, &stack);
	}
	else if (argc == 2)
		ft_check_args(argc, argv);
}
