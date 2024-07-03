/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:41:52 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/08 16:06:02 by mtigunit         ###   ########.fr       */
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

int	t_map_getelement(t_map *map, int x, int y)
{
	if (!map || !map->data)
		return (0);
	if ((y < 0) || (y >= map->height) || (x < 0) || (x >= map->width))
		return (0);
	return (map->data[y][x]);
}

int	t_map_setelement(t_map *map, int x, int y, char c)
{
	if (!map || !map->data)
		return (0);
	if ((y < 0) || (y >= map->height) || (x < 0) || (x >= map->width))
		return (0);
	map->data[y][x] = c;
	return (c);
}

int	t_map_isempty(t_map *map, int x, int y)
{
	char	c;

	if (!map || !map->data)
		return (0);
	if ((y < 0) || (y >= map->height) || (x < 0) || (x >= map->width))
		return (0);
	c = map->data[y][x];
	if ((c == '0') || (c == 'E') || (c == 'N') || (c == 'S'))
		return (1);
	if ((c == 'W') || (c == 'O'))
		return (1);
	return (0);
}

int	t_map_issprite(t_map *map, int x, int y)
{
	char	c;

	c = t_map_getelement(map, x, y);
	return (0 <= t_map_sprite_index(c));
}

int	t_map_isfilled(t_map *map, int x, int y)
{
	if (!map || (y < 0) || (y >= map->height) || (x < 0) || (x >= map->width))
		return (1);
	return (!t_map_isempty(map, x, y));
}
