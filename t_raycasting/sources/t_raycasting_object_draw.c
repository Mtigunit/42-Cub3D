/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_object_draw.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:16:54 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:37 by ahabachi         ###   ########.fr       */
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

int	t_raycasting_object_init(t_raycasting *ray)
{
	int					sprite_id;
	t_raycasting_object	*object;

	if (!ray || !ray->object || !ray->cub || !ray->cub->image)
		return (1);
	object = ray->object;
	sprite_id = t_map_sprite_index(object->identifier);
	object->texture = 0;
	if (0 <= sprite_id && sprite_id < ray->cub->sprites_number)
		object->texture = ray->cub->sprites[sprite_id];
	if ((object->start_distance < 0) || (object->mid_distance <= 0.001))
		return (1);
	object->height = ray->cub->screen_dist
		/ ft_limit(ray->object->mid_distance);
	object->width = ray->cub->scale * (ray->number - ray->object->ray_start);
	object->x = ray->object->ray_start * ray->cub->scale;
	object->y = ((ray->cub->height / 2.0) - object->height / 2);
	if (object->y + object->height > ray->cub->image->height)
		object->height = ray->cub->image->height - object->y;
	if (object->width < object->height && object->x == 0)
		object->x = object->width - object->height;
	if (((object->width < object->height) && (ray->cub->image->width < 2
				* object->x)) || (object->width > object->height))
		object->width = object->height;
	return (0);
}

void	t_raycasting_object_draw(t_raycasting *ray)
{
	if (t_raycasting_object_init(ray))
		return ;
	if (!ray || !ray->cub || !ray->cub->image || !ray->object->texture)
		return ;
	t_surface_copy(ray->cub->image, ray->object->texture,
		(int []){
		ray->object->x, ray->object->y, ray->object->width, ray->object->height,
	}, (int []){
		0, 0, ray->object->texture->width, ray->object->texture->height});
}
