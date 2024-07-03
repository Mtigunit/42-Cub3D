/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:54:06 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:17 by ahabachi         ###   ########.fr       */
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

t_player	*t_player_init(t_player *player, t_cub3d *cub)
{
	if (!player)
		return (player);
	player->cub = cub;
	player->rotation_speed = DEFAULT_PLAYER_ROT_SPEED;
	player->speed = DEFAULT_PLAYER_SPEED;
	player->angle = DEFAULT_PLAYER_ANGLE;
	player->size = 14;
	if (cub && cub->map)
	{
		player->x = cub->map->player_x + 0.5;
		player->y = cub->map->player_y + 0.5;
		if (t_map_getelement(cub->map, (int) player->x, (int) player->y) == 'N')
			player->angle = -M_PI / 2;
		if (t_map_getelement(cub->map, (int) player->x, (int) player->y) == 'S')
			player->angle = M_PI / 2;
		if (t_map_getelement(cub->map, (int) player->x, (int) player->y) == 'W')
			player->angle = M_PI;
		if (t_map_getelement(cub->map, (int) player->x, (int) player->y) == 'E')
			player->angle = 0.0;
	}
	return (player);
}
