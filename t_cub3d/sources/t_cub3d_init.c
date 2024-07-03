/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_cub3d_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:50:44 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:44 by ahabachi         ###   ########.fr       */
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

static int	ft_loop_hook(t_cub3d *cub)
{
	if (!cub || cub->pause)
		return (0);
	ft_timestamp(cub->width / 14);
	if (t_cub3d_loading(cub))
	{
		t_cub3d_draw(cub);
	}
	else
	{
		t_cub3d_update(cub);
		t_cub3d_draw(cub);
	}
	return (1);
}

t_cub3d	*t_cub3d_init_textures(t_cub3d *cub)
{
	int		i;
	int		c;
	char	filename[32];

	if (!cub || !cub->mlx || !cub->map)
		return (cub);
	c = 0;
	ft_memcpy(filename, "assets/animations/sprite-a/\0", 28);
	while (c < 256)
	{
		i = t_map_sprite_index(c);
		if (0 <= i)
		{
			filename[25] = c;
			cub->sprites[i] = t_surface_load(cub->mlx, filename);
		}
		c++;
	}
	cub->door = t_surface_load(cub->mlx, "assets/textures/door.xpm");
	cub->loading = t_surface_load(cub->mlx, "assets/animations/loading");
	cub->no_texture = t_surface_load(cub->mlx, cub->map->no);
	cub->so_texture = t_surface_load(cub->mlx, cub->map->so);
	cub->we_texture = t_surface_load(cub->mlx, cub->map->we);
	cub->ea_texture = t_surface_load(cub->mlx, cub->map->ea);
	return (cub);
}

void	t_cub3d_inithooks(t_cub3d *cub)
{
	if (!cub || !cub->mlx || !cub->win)
		return ;
	mlx_hook(cub->win, 2, 1L << 0, ft_keyboard_events, cub);
	mlx_loop_hook(cub->mlx, (void *) ft_loop_hook, cub);
	mlx_hook(cub->win, 6, 0, t_cub3d_onmousemove, cub);
	mlx_hook(cub->win, EVENT_ON_DESTROY, 0, t_cub3d_stop, cub);
	mlx_hook(cub->win, 4, 0, t_cub3d_onmousedown, cub);
	mlx_hook(cub->win, 5, 0, t_cub3d_onmouseup, cub);
}

void	t_cub3d_initwindow(t_cub3d *cub)
{
	char	*image_data;

	if (!cub || !cub->image || (cub->width < 100) || (cub->height < 100))
		return ;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return ;
	if (!cub->title)
		cub->title = "cub3D";
	cub->win = mlx_new_window(cub->mlx, cub->width, cub->height, cub->title);
	if (!cub->win)
		return ;
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	if (!cub->img)
		return ;
	image_data = mlx_get_data_addr(cub->img, &cub->image->bpp,
			&cub->image->line_length, &cub->image->endian);
	t_surface_setbuffer(cub->image, image_data);
	cub->image->mlx = cub->mlx;
	cub->image->img = cub->img;
	t_cub3d_init_textures(cub);
	t_cub3d_inithooks(cub);
}

t_cub3d	*t_cub3d_init(t_cub3d *cub)
{
	if (!cub)
		return (cub);
	cub->image = t_surface_new(cub->width, cub->height);
	cub->player = t_player_init(cub->player, cub);
	t_cub3d_initwindow(cub);
	return (cub);
}
