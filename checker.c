/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:35:57 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/12 10:02:02 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

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
		print_error();
}

static void	get_output(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		check_standard_input(str, stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
}

static void	check_stacks(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (is_sorted(stack_a) && !ft_lstsize(stack_b)
		&& ft_lstsize(stack_a) == argc)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	char	*args_str;

	if (argc <= 1)
		exit(0);
	args_str = args_to_str(argc, argv);
	args = ft_split(args_str, ' ');
	argc = arglen(args);
	if (argc > 1)
	{
		ft_check_args(argc, args);
		ft_check_duplicated(argc, args);
		stack_a = ft_lstnew(ft_atoi(args[0]));
		i = 1;
		while (i < argc)
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(args[i++])));
		get_output(&stack_a, &stack_b);
		check_stacks(stack_a, stack_b, argc);
	}
	else if (argc == 2)
		ft_check_args(argc, args);
	free_args(args, argc);
}
