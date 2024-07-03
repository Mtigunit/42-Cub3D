/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:01:17 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:13:36 by mtigunit         ###   ########.fr       */
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

static void	init_player(t_map *p, int x, int y, int *player_flag)
{
	if (p && player_flag)
	{
		p->player_x = x;
		p->player_y = y;
		(*player_flag)++;
	}
}

static void	check_player(int player_flag)
{
	if (player_flag != 1)
		return (print_error("player_flag: Invalid map.\n"), exit(1));
}

char	**parce_map(t_map *p, char **map, int map_len)
{
	int		x;
	int		y;
	int		player_flag;

	if (!p || !map || !*map)
		return (NULL);
	y = -1;
	player_flag = 0;
	while (map[++y])
	{
		x = check_first_column(map, y) - 1;
		while (map[y][++x])
		{
			if (map[y][x] == '0')
				parce_zero(map, x, y, map_len);
			else if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
				init_player(p, x, y, &player_flag);
			else if (map[y][x] == 'O' || map[y][x] == 'C')
				parce_door(map, x, y, map_len);
			else
				continue ;
		}
	}
	return (check_player(player_flag), copy_map(p, map), map);
}
