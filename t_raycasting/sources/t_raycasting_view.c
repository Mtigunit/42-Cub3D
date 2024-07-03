/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:00:05 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:45 by ahabachi         ###   ########.fr       */
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

int	t_raycasting_front_view(t_raycasting *ray)
{
	if (ray && ray->cub && (ray->wall == VERTICAL) && (0 <= ray->adjacent))
	{
		ray->wallcolor = DEFAULT_FRONT_WALL_COLOR;
		ray->texture = ray->cub->ea_texture;
		return (1);
	}
	return (0);
}

int	t_raycasting_back_view(t_raycasting *ray)
{
	if (ray && ray->cub && (ray->wall == VERTICAL) && (ray->adjacent <= 0))
	{
		ray->wallcolor = DEFAULT_BACK_WALL_COLOR;
		ray->texture = ray->cub->we_texture;
		return (1);
	}
	return (0);
}

int	t_raycasting_left_view(t_raycasting *ray)
{
	if (ray && ray->cub && (ray->wall == HORIZONTAL) && (0 <= ray->opposite))
	{
		ray->wallcolor = DEFAULT_LEFT_WALL_COLOR;
		ray->texture = ray->cub->no_texture;
		return (1);
	}
	return (0);
}

int	t_raycasting_right_view(t_raycasting *ray)
{
	if (ray && ray->cub && (ray->wall == HORIZONTAL) && (ray->opposite <= 0))
	{
		ray->wallcolor = DEFAULT_RIGHT_WALL_COLOR;
		ray->texture = ray->cub->so_texture;
		return (1);
	}
	return (0);
}

int	t_raycasting_view(t_raycasting *ray, int x, int y)
{
	if (t_map_getelement(ray->cub->map, x, y) == 'C')
	{
		ray->wallcolor = DEFAULT_DOOR_COLOR;
		ray->texture = ray->cub->door;
		return (1);
	}
	else if (t_raycasting_front_view(ray))
		return (1);
	else if (t_raycasting_back_view(ray))
		return (1);
	else if (t_raycasting_left_view(ray))
		return (1);
	else if (t_raycasting_right_view(ray))
		return (1);
	return (0);
}
