/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:18:47 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 16:39:50 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!lst)
		return ;
	while ((*lst))
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = curr;
	}
	lst = NULL;
}
