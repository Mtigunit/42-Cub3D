/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:14:47 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:17:40 by mtigunit         ###   ########.fr       */
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

static void	init_colors(t_map *p)
{
	if (p)
	{
		p->f[0] = -1;
		p->f[1] = -1;
		p->f[2] = -1;
		p->c[0] = -1;
		p->c[1] = -1;
		p->c[2] = -1;
	}
}

int	init_map(t_map *p, char *path)
{
	int		fd;
	char	*tmp_line;
	char	**tmp_map;

	if (!p || !path)
		return (print_error(""), exit(1), FAILURE);
	init_colors(p);
	fd = open_file(path);
	parce_texture_and_colors(p, fd);
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		return (print_error("Invalid map\n"), exit(1), 1);
	p->height = 0;
	tmp_map = NULL;
	tmp_map = get_map(tmp_map, tmp_line, fd, &p->height);
	if (check_wall_line(tmp_map[0]) == FAILURE
		|| check_wall_line(tmp_map[p->height - 1]) == FAILURE)
		return (print_error("Invalid map\n"), exit(1), 1);
	if (tmp_map[p->height - 1][ft_strlen(tmp_map[p->height - 1]) - 1] == '\n')
		return (print_error("Invalid map\n"), exit(1), 1);
	p->data = parce_map(p, tmp_map, p->height);
	if (!p->data)
		return (print_error("p->data: Invalid map.\n"), exit(1), FAILURE);
	return (close(fd), SUCCESS);
}
