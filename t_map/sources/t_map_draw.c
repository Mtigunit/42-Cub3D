/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_map_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:00:06 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/08 14:03:27 by mtigunit         ###   ########.fr       */
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

void	t_map_draw_coordinates(t_map *map, int map_width, int map_height)
{
	if (!map)
		return ;
	map->start_x = (map->cub->player->x) - (map_width / 2);
	map->start_y = (map->cub->player->y) - (map_height / 2);
	if (map->width - map->cub->player->x < (map_width / 2))
		map->start_x = map->width - map_width;
	if (map->height - map->cub->player->y < (map_height / 2))
		map->start_y = map->height - map_height;
	if (map->start_x < 0)
		map->start_x = 0;
	if (map->start_y < 0)
		map->start_y = 0;
	while ((map_width < map->size) && (map_height < map->size))
	{
		map_width *= 1.2;
		map_height *= 1.2;
		map->scale *= 1.2;
	}
	if (map_width > map->width)
		map_width = map->width;
	if (map_height > map->height)
		map_height = map->height;
}

int	t_map_draw_acquire(t_map *map)
{
	float	map_width;
	float	map_height;

	if (!map || !map->cub || !map->cub->image || !map->cub->player)
		return (1);
	if (map->cub->hidemap)
		return (1);
	map->scale = 5;
	map->size = 40;
	map_width = map->size;
	map_height = map->size;
	if (map_width > map->width)
		map_width = map->width;
	if (map_height > map->height)
		map_height = map->height;
	t_map_draw_coordinates(map, map_width, map_height);
	t_surface_setcolor(map->cub->image, 0x00888888);
	t_surface_rect(map->cub->image, (int []){0, 0,
		map_width * map->scale, map_height * map->scale}, 0);
	return (0);
}

void	t_map_draw_element(t_map *map, int i, int j)
{
	int	x;
	int	y;

	if (!map || !map->cub || !map->cub->image)
		return ;
	x = i + map->start_x;
	y = j + map->start_y;
	t_surface_setcolor(map->cub->image, 0x00000000);
	if (t_map_getelement(map, x, y) == 'C')
		t_surface_setcolor(map->cub->image, 0x00FF0000);
	if (!t_map_isempty(map, x, y))
		t_surface_rect(map->cub->image, (int []){i * map->scale,
			j * map->scale, map->scale, map->scale}, 0);
}

t_map	*t_map_draw(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->cub || !map->cub->image || !map->cub->player)
		return (map);
	if (t_map_draw_acquire(map))
		return (map);
	j = 0;
	while ((j < map->size) && (j < map->height))
	{
		i = 0;
		while ((i < map->size) && (i < map->width))
		{
			t_map_draw_element(map, i, j);
			i++;
		}
		j++;
	}
	t_surface_setcolor(map->cub->image, 0x00000000);
	t_surface_rect(map->cub->image, (int []){(map->cub->player->x
			- map->start_x) * map->scale, (map->cub->player->y - map->start_y)
		* map->scale, map->scale / 2, map->scale / 2}, 0);
	return (map);
}
