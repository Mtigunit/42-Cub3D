/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:19:52 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:35 by ahabachi         ###   ########.fr       */
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

static t_real	t_raycasting_vertical_intersection_distance(t_raycasting *ray)
{
	float	d;

	ray->dy = (ray->y - ray->cub->player->y);
	ray->dx = ray->dy / ft_limit(ray->tangente);
	ray->x = ray->dx + ray->cub->player->x;
	d = sqrt(ray->dx * ray->dx + ray->dy * ray->dy);
	if (ray->opposite == 0.0)
		ray->dot_product = 0.0;
	else
		ray->dot_product = ray->dy / ft_limit(ray->opposite);
	return (d);
}

static t_real	t_raycasting_vertical_intersection(t_raycasting *ray)
{
	float	d;

	ray->y = 0;
	while (ray->y < ray->cub->map->height)
	{
		d = t_raycasting_vertical_intersection_distance(ray);
		t_raycasting_close_door(ray->cub->map, (int) ray->x,
			(int) ray->y - (ray->opposite < 0), d);
		if ((ray->dot_product >= 0) && (d < ray->distance))
		{
			if (t_map_isfilled(ray->cub->map, (int) ray->x,
					(int) ray->y - (ray->opposite < 0)))
			{					
				ray->identifier = t_map_getelement(ray->cub->map,
						(int) ray->x, (int) ray->y - (ray->opposite < 0));
				ray->distance = d;
				ray->inter_x = ray->x;
				ray->inter_y = ray->y;
			}
		}
		ray->y = ray->y + 1;
	}
	return (ray->distance);
}

static t_real	t_raycasting_horizontal_intersection_distance(t_raycasting *ray)
{
	float	d;

	ray->dx = ray->x - ray->cub->player->x;
	ray->y = ray->tangente * ray->dx + ray->cub->player->y;
	ray->dy = ray->y - ray->cub->player->y;
	d = sqrt(ray->dx * ray->dx + ray->dy * ray->dy);
	if (ray->adjacent == 0.0)
		ray->dot_product = 0.0;
	else
		ray->dot_product = ray->dx / ft_limit(ray->adjacent);
	return (d);
}

static t_real	t_raycasting_horizontal_intersection(t_raycasting *ray)
{
	float	d;

	ray->x = 0;
	while (ray->x < ray->cub->map->width)
	{
		d = t_raycasting_horizontal_intersection_distance(ray);
		t_raycasting_close_door(ray->cub->map, (int) ray->x
			- (ray->adjacent < 0), (int) ray->y, d);
		if ((ray->dot_product >= 0) && (d < ray->distance))
		{
			if (t_map_isfilled(ray->cub->map, (int) ray->x
					- (ray->adjacent < 0), (int) ray->y))
			{
				ray->identifier = t_map_getelement(ray->cub->map,
						(int) ray->x - (ray->adjacent < 0), (int) ray->y);
				ray->wall = VERTICAL;
				ray->distance = d;
				ray->inter_x = ray->x;
				ray->inter_y = ray->y;
			}
		}
		ray->x = ray->x + 1;
	}
	return (ray->distance);
}

t_real	t_raycasting_intersection(t_raycasting *ray)
{
	if (!ray || !ray->cub || !ray->cub->map)
		return (0.0);
	ray->wall = HORIZONTAL;
	ray->opposite = ft_limit(sin(ray->angle));
	ray->adjacent = ft_limit(cos(ray->angle));
	ray->tangente = ft_limit(tan(ray->angle));
	ray->distance = 100000000;
	ray->inter_x = 100000000;
	ray->inter_y = 100000000;
	t_raycasting_vertical_intersection(ray);
	t_raycasting_horizontal_intersection(ray);
	return (ray->distance);
}
