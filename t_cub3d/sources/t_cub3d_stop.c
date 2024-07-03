/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_cub3d_stop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:42:46 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:56 by ahabachi         ###   ########.fr       */
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

t_cub3d	*t_cub3d_del(t_cub3d *cub)
{
	int	i;
	int	c;

	if (!cub)
		return (cub);
	if (cub->map)
		cub->map = ft_free_struct(cub->map);
	c = 0;
	while (c < 256)
	{
		i = t_map_sprite_index(c);
		if (0 <= i)
			t_surface_del(cub->sprites[i]);
		c++;
	}
	t_surface_del(cub->door);
	t_surface_del(cub->loading);
	t_surface_del(cub->no_texture);
	t_surface_del(cub->so_texture);
	t_surface_del(cub->we_texture);
	t_surface_del(cub->ea_texture);
	t_surface_del(cub->image);
	return ((t_cub3d *)0);
}

int	t_cub3d_stop(t_cub3d *cub)
{
	if (!cub)
		return (exit(0), 1);
	t_cub3d_del(cub);
	return (exit(0), 0);
}
