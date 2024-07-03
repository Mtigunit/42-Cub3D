/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:14:01 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:14:23 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*  █████████            ██████████         ██████████         ██████████     */
/*  ██     ██                    ██                 ██         ██      ██     */
/*         ██                    ██                 ██         ██      ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██            ██████████         ██████████                 ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██                    ██                 ██                 ██     */
/*      ████████         ██████████         ██████████                 ██     */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**get_map(char **tmp_map, char *tmp_line, int fd, int *map_len)
{
	t_list	*lst;

	lst = NULL;
	while (tmp_line && tmp_line[0] == '\n')
	{
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	ft_lstadd_back(&lst, ft_lstnew((char *)tmp_line));
	while (tmp_line)
	{
		tmp_line = get_next_line(fd);
		ft_lstadd_back(&lst, ft_lstnew((char *)tmp_line));
		(*map_len)++;
	}
	tmp_map = (char **)ft_calloc(*map_len + 1, sizeof(char *));
	*map_len = 0;
	while (lst)
	{
		if (lst->content)
			tmp_map[(*map_len)++] = (char *)lst->content;
		free(lst);
		lst = lst->next;
	}
	return (tmp_map[*map_len] = NULL, tmp_map);
}
