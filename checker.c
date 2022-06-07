/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:35:57 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 18:03:29 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_standard_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_sa(*stack_a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		ft_sb(*stack_b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ft_ss(*stack_a, *stack_b, 0);
	else if (!ft_strcmp(str, "ra\n"))
		ft_ra(stack_a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rb(stack_b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		ft_rra(stack_a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_rrb(stack_b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		ft_rrr(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		ft_pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		ft_pb(stack_a, stack_b, 0);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 2)
	{
		ft_check_args(argc, argv);
		ft_check_int_range(argc, argv);
		ft_check_duplicated(argc, argv);
		stack_a = ft_lstnew(ft_atoi(argv[1]));
		i = 2;
		while (i < argc)
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i++])));
		str = get_next_line(0); // fd = 0 => standard input
		while (str)
		{
			check_standard_input(str, &stack_a, &stack_b);
			str = get_next_line(0);
		}
		if (is_sorted(stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else if (argc == 2)
	{
		ft_check_args(argc, argv);
		ft_check_int_range(argc, argv);
	}
}
