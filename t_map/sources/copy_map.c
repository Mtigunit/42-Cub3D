/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:45:03 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 09:46:06 by mtigunit         ###   ########.fr       */
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

static int	get_maxlen(char **map)
{
	int	maxlen;
	int	line_len;
	int	i;

	if (!map || !*map)
		return (print_error("copy_map: Invalid map.\n"), exit(1), FAILURE);
	i = 0;
	maxlen = 0;
	i = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if ((line_len > 0) && (map[i][line_len - 1] == '\n'))
			line_len--;
		if (line_len > maxlen)
			maxlen = line_len;
		i++;
	}
	return (maxlen);
}

void	copy_map(t_map *p, char **map)
{
	int		i;
	int		j;
	char	*tmp;

	if (!p || !map || !*map)
		return (print_error("copy_map: Invalid map.\n"), exit(1));
	p->width = get_maxlen(map);
	i = -1;
	while (map[++i])
	{
		tmp = map[i];
		map[i] = ft_calloc(p->width + 1, sizeof(char));
		j = -1;
		while (tmp[++j])
			map[i][j] = tmp[j];
		if (map[i][j - 1] == '\n')
			j--;
		while (j < p->width)
			map[i][j++] = ' ';
		map[i][p->width] = 0;
		free(tmp);
	}
}
