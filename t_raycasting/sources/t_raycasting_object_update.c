/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_object_update.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:50:18 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:42 by ahabachi         ###   ########.fr       */
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

void	t_raycasting_object_enter(t_raycasting *ray)
{
	if (ray && ray->object && ray->object->ray_start < 0)
	{
		ray->object->start_wall = ray->wall;
		ray->object->ray_start = ray->number;
		ray->object->angle_start = ray->angle;
		ray->object->start_x = ray->inter_x;
		ray->object->start_y = ray->inter_y;
		ray->object->start_distance = ray->distance;
	}
}

void	t_raycasting_object_update(t_raycasting *ray)
{
	if (ray && ray->object && (0 <= t_map_sprite_index(ray->identifier)))
	{
		ray->object->identifier = ray->identifier;
		if (ray->object->ray_start < 0)
			t_raycasting_object_enter(ray);
		if (
			(ray->object->mid_distance < 0)
			|| (ray->distance <= ray->object->mid_distance))
		{
			ray->object->mid_x = ray->inter_x;
			ray->object->mid_y = ray->inter_y;
			ray->object->mid_distance = ray->distance;
		}
		ray->object->end_x = ray->inter_x;
		ray->object->end_y = ray->inter_y;
		ray->object->end_distance = ray->distance;
	}
	else
	{
		t_raycasting_object_draw(ray);
		t_raycasting_object_reset(ray->object);
	}
}
