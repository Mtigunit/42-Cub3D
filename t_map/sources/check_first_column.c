/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_column.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:12:36 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:12:46 by mtigunit         ###   ########.fr       */
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

int	check_first_column(char **map, int y)
{
	int	x;

	if (!map || !*map)
		return (print_error("parce_map: Invalid map.\n"), exit(1), FAILURE);
	x = 0;
	skip_white_spaces(map[y], &x);
	if (map[y][x] != '1' || map[y][ft_strlen(map[y]) - 2] != '1')
		return (print_error("parce_map: Invalid map.\n"), exit(1), FAILURE);
	return (x);
}