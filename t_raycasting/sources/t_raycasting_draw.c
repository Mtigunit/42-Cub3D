/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:53:03 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:30 by ahabachi         ###   ########.fr       */
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

static t_raycasting	*t_raycasting_draw_texture(t_raycasting *ray)
{
	if (!ray || !ray->texture || !ray->cub || !ray->cub->image)
		return (ray);
	ray->texture_offset = (int)(ray->texture->width
			* (ray->inter_x - floor(ray->inter_x)));
	if (ray->wall == VERTICAL)
		ray->texture_offset = (int)(ray->texture->width
				* (ray->inter_y - floor(ray->inter_y)));
	t_surface_copy(
		ray->cub->image, ray->texture,
		(int []){
		ray->number * ray->cub->scale, ((ray->cub->height / 2.0)
			- ray->projected_height / 2.0),
		ray->cub->scale, ray->projected_height
	}, (int []){
		ray->texture_offset, 0, ray->cub->scale, ray->texture->height
	});
	return (ray);
}

t_raycasting	*t_raycasting_draw(t_raycasting *ray)
{
	if (!ray || !ray->cub || !ray->cub->image)
		return (ray);
	if (ray->texture)
	{
		t_surface_setcolor(ray->cub->image,
			t_surface_getpixel(ray->texture, 1, 1));
		t_surface_rect(ray->cub->image, (int []){ray->number * ray->cub->scale,
			(ray->cub->height / 2.0) - ray->projected_height / 2.0,
			ray->cub->scale, ray->projected_height}, 1);
		return (t_raycasting_draw_texture(ray));
	}
	t_surface_setcolor(ray->cub->image, ray->wallcolor);
	t_surface_rect(ray->cub->image, (int []){ray->number * ray->cub->scale,
		(ray->cub->height / 2.0) - ray->projected_height / 2.0,
		ray->cub->scale, ray->projected_height}, 1);
	return (ray);
}
