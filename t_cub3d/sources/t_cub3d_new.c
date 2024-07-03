/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_cub3d_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:50:57 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:49 by ahabachi         ###   ########.fr       */
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

static t_cub3d	*t_cub3d_newcub(void)
{
	static t_cub3d	cub;

	return (&cub);
}

t_cub3d	*t_cub3d_new(char *filename, int width, int height)
{
	t_cub3d	*cub;

	if (!filename || width < 100 || height < 100)
		return ((t_cub3d *)0);
	cub = t_cub3d_newcub();
	cub->fov = (M_PI / 3.0);
	cub->num_rays = (width / 2.0);
	cub->delta_angle = (cub->fov / cub->num_rays);
	cub->screen_dist = ((width / 2.0) / tan(cub->fov / 2));
	cub->scale = (width / cub->num_rays);
	cub->sprites_number = MAX_SPRITES_NUMBER;
	cub->raycasting = t_raycasting_new(cub);
	cub->player = t_player_new(cub);
	cub->width = width;
	cub->height = height;
	cub->map = t_map_new(filename);
	cub->map->cub = cub;
	cub->mouse_pressed_x = -1;
	cub->mouse_pressed_y = -1;
	cub->loading = 0;
	cub->title = "cub3D";
	cub->hidemap = 1;
	return (cub);
}
