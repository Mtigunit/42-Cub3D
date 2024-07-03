/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:10:40 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/05 13:51:28 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = ft_lstsize(lst);
	while (i > 1)
	{
		i--;
		lst = lst->next;
	}
	return (lst);
}
