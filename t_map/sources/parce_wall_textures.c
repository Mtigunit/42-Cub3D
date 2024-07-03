/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_wall_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:10:03 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:48:58 by mtigunit         ###   ########.fr       */
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

int	parce_wall_textures(const char *str, char **identifier)
{
	int			fd;
	static int	dup;

	if (!str || !identifier)
		return (print_error("parce_wall_textures 1\n"), exit(1), 1);
	if (*identifier)
		return (print_error("parce_wall_textures 2\n"), exit(1), 1);
	*identifier = ft_strtrim(str, "\t\n\r\f\v\b ");
	if (!*identifier)
		return (print_error("parce_wall_textures 3\n"), exit(1), 1);
	texture_extension(*identifier);
	fd = open(*identifier, O_RDONLY);
	if (fd < 0)
		return (print_error("fd: Invalid texture.\n"), exit(1), FAILURE);
	close(fd);
	if (dup > 4)
		return (print_error("dup: Invalid map\n"), exit(1), 1);
	dup++;
	return (SUCCESS);
}
