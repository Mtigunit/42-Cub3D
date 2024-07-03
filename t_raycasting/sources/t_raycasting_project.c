/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_project.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:08:34 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:44 by mtigunit         ###   ########.fr       */
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

t_raycasting	*t_raycasting_project(t_raycasting *ray)
{
	int	x;
	int	y;

	if (!ray || !ray->cub || !ray->cub->player || ray->distance < 0.001)
		return (ray);
	ray->texture = (t_surface *)0;
	ray->distance *= cos(ray->cub->player->angle - ray->angle);
	ray->projected_height = ray->cub->screen_dist / ft_limit(ray->distance);
	x = ray->inter_x;
	y = ray->inter_y;
	if (ray->wall == VERTICAL)
		x -= (cos(ray->angle) < 0);
	else
		y -= (sin(ray->angle) < 0);
	t_raycasting_view(ray, x, y);
	return (ray);
}
