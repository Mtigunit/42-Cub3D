/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_player_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:54:13 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:20 by mtigunit         ###   ########.fr       */
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

t_player	*t_player_collision(t_player *player, t_real dx, t_real dy)
{
	t_map	*map;
	int		xsign;
	int		ysign;

	if (!player || !player->cub || !player->cub->map)
		return (player);
	map = player->cub->map;
	xsign = 1.0 * ((dx >= 0) - (dx < 0));
	ysign = 1.0 * ((dy >= 0) - (dy < 0));
	if (t_map_isempty(map, (int)(player->x + xsign), (int)player->y))
		player->x += dx;
	if (t_map_isempty(map, (int)player->x, (int)(player->y + ysign)))
		player->y += dy;
	return (player);
}

t_player	*t_player_move_left(t_player *player)
{
	t_real	dx;
	t_real	dy;

	if (!player)
		return (player);
	dx = player->speed * sin(player->angle);
	dy = -player->speed * cos(player->angle);
	t_player_collision(player, dx, dy);
	return (player);
}

t_player	*t_player_move_right(t_player *player)
{
	t_real	dx;
	t_real	dy;

	if (!player)
		return (player);
	dx = -player->speed * sin(player->angle);
	dy = player->speed * cos(player->angle);
	t_player_collision(player, dx, dy);
	return (player);
}

t_player	*t_player_move_forward(t_player *player)
{
	t_real	dx;
	t_real	dy;

	if (!player)
		return (player);
	dx = player->speed * cos(player->angle);
	dy = player->speed * sin(player->angle);
	t_player_collision(player, dx, dy);
	return (player);
}

t_player	*t_player_move_backward(t_player *player)
{
	t_real	dx;
	t_real	dy;

	if (!player)
		return (player);
	dx = -player->speed * cos(player->angle);
	dy = -player->speed * sin(player->angle);
	t_player_collision(player, dx, dy);
	return (player);
}
