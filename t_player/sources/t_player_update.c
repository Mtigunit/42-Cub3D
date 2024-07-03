/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_player_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:54:20 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:23 by mtigunit         ###   ########.fr       */
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

t_player	*t_player_movement(t_player *player)
{
	if (!player || !player->cub)
		return (player);
	if ((player->cub->keycode == KEYCODE_W)
		|| (player->cub->keycode == KEYCODE_ARROW_UP))
		t_player_move_forward(player);
	else if ((player->cub->keycode == KEYCODE_S)
		|| (player->cub->keycode == KEYCODE_ARROW_DOWN))
		t_player_move_backward(player);
	else if (player->cub->keycode == KEYCODE_A)
		t_player_move_left(player);
	else if (player->cub->keycode == KEYCODE_D)
		t_player_move_right(player);
	if (player->cub->keycode == KEYCODE_ARROW_LEFT)
		player->angle -= player->rotation_speed;
	if (player->cub->keycode == KEYCODE_ARROW_RIGHT)
		player->angle += player->rotation_speed;
	while (player->angle > 2 * 3.1415926538)
		player->angle -= 2 * 3.1415926538;
	while (player->angle < 0)
		player->angle += 2 * 3.1415926538;
	return (player);
}

void	t_player_check_sides(t_player *player, t_real x, t_real y, t_real d)
{
	if (!player || !player->cub || !player->cub->map)
		return ;
	if (t_map_getelement(player->cub->map, x, y) == 'C')
		t_map_setelement(player->cub->map, x, y, 'O');
	else if (t_map_getelement(player->cub->map, x + d, y) == 'C')
		t_map_setelement(player->cub->map, x + d, y, 'O');
	else if (t_map_getelement(player->cub->map, x + d, y + d) == 'C')
		t_map_setelement(player->cub->map, x + d, y + d, 'O');
	else if (t_map_getelement(player->cub->map, x, y + d) == 'C')
		t_map_setelement(player->cub->map, x, y + d, 'O');
	else if (t_map_getelement(player->cub->map, x - d, y + d) == 'C')
		t_map_setelement(player->cub->map, x - d, y + d, 'O');
	else if (t_map_getelement(player->cub->map, x - d, y) == 'C')
		t_map_setelement(player->cub->map, x - d, y, 'O');
	else if (t_map_getelement(player->cub->map, x - d, y - d) == 'C')
		t_map_setelement(player->cub->map, x - d, y - d, 'O');
	else if (t_map_getelement(player->cub->map, x, y - d) == 'C')
		t_map_setelement(player->cub->map, x, y - d, 'O');
	else if (t_map_getelement(player->cub->map, x + d, y - d) == 'C')
		t_map_setelement(player->cub->map, x + d, y - d, 'O');
}

t_player	*t_player_open_door(t_player *player)
{
	t_real	x;
	t_real	y;
	t_real	d;

	if (!player)
		return (player);
	d = MIN_DOOR_DISTANCE;
	x = player->x + d * cos(player->angle);
	y = player->y + d * sin(player->angle);
	t_player_check_sides(player, x, y, d);
	return (player);
}

t_player	*t_player_update(t_player *player)
{
	if (!player || !player->cub)
		return (player);
	if (player->cub->keycode == KEYCODE_PLUS)
		player->speed += PLAYER_ACCELERATION;
	if (player->cub->keycode == KEYCODE_MINUS)
		player->speed -= PLAYER_ACCELERATION;
	if (player->speed < 0.1)
		player->speed = 0.1;
	if (player->speed > 0.9)
		player->speed = 0.9;
	t_player_movement(player);
	t_player_open_door(player);
	return (player);
}
