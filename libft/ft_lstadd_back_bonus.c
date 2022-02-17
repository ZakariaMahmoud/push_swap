/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:39:50 by zmahmoud          #+#    #+#             */
/*   Updated: 2021/11/27 01:47:08 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}
