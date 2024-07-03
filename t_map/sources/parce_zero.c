/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:10:56 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:11:20 by mtigunit         ###   ########.fr       */
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

int	parce_zero(char **map, int x, int y, int map_len)
{
	if (!map || !*map)
		return (print_error("parce_zero: Invalid map.\n"), exit(1), FAILURE);
	if (x >= 0 && y >= 0 && y < map_len && (size_t)x < ft_strlen(map[y]))
	{
		if (!ft_isalnum(map[y + 1][x]))
			return (print_error("parce_zero: Invalid map.\n"), exit(1), FAILURE);
		if (!ft_isalnum(map[y - 1][x]))
			return (print_error("parce_zero: Invalid map.\n"), exit(1), FAILURE);
		if (!ft_isalnum(map[y][x + 1]))
			return (print_error("parce_zero: Invalid map.\n"), exit(1), FAILURE);
		if (!ft_isalnum(map[y][x - 1]))
			return (print_error("parce_zero: Invalid map.\n"), exit(1), FAILURE);
	}
	return (SUCCESS);
}
