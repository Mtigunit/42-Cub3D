/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:00:05 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:45 by mtigunit         ###   ########.fr       */
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

t_raycasting	*t_raycasting_update(t_raycasting *ray)
{
	t_raycasting_object	object;

	if (!ray || !ray->cub || !ray->cub->player)
		return (ray);
	ray->cub->player->angle = fmod(ray->cub->player->angle, M_PI * 2);
	ray->angle = ray->cub->player->angle - ray->cub->fov * 0.5 + 0.0001;
	ray->cub->player->angle = fmod(ray->cub->player->angle, M_PI * 2);
	ray->number = 0;
	ray->object = &object;
	t_raycasting_object_reset(ray->object);
	while (ray->number <= ray->cub->num_rays)
	{
		t_raycasting_intersection(ray);
		t_raycasting_object_update(ray);
		t_raycasting_project(ray);
		t_raycasting_draw(ray);
		ray->angle += ray->cub->delta_angle;
		ray->number++;
	}
	t_raycasting_object_draw(ray);
	t_raycasting_object_reset(ray->object);
	return (ray);
}
