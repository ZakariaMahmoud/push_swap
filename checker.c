/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:35:57 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/07 10:51:28 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack;

	if (argc > 2)
	{
		ft_check_args(argc, argv);
		ft_check_int_range(argc, argv);
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

// int main()
// {
// 	char	*str;
// 	int		fd;

// 	fd = 0; // fd = 0 => standard input
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		if (!ft_strcmp(str, "sa\n"))
// 			printf("Yes"); 
// 		str = get_next_line(fd);
// 	}
	
// }
