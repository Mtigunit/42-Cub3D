/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_texture_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:59:08 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 09:59:53 by mtigunit         ###   ########.fr       */
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

static int	parce_t_and_c_help(t_map *p, char *tmp_line, int i)
{
	skip_white_spaces(&tmp_line[i], &i);
	if (tmp_line[i] && tmp_line[i + 1]
		&& (tmp_line[i] == 'C' && !ft_isalpha(tmp_line[i + 1])))
		parce_cf(tmp_line + i + 2, p->c);
	if (tmp_line[i] && tmp_line[i + 1]
		&& (tmp_line[i] == 'F' && !ft_isalpha(tmp_line[i + 1])))
		parce_cf(tmp_line + i + 2, p->f);
	if (tmp_line[i] && tmp_line[i + 1] && tmp_line[i + 2]
		&& (tmp_line[i] == 'N' && tmp_line[i + 1] == 'O'
			&& !ft_isalpha(tmp_line[i + 2])))
		parce_wall_textures(tmp_line + i + 3, &p->no);
	if (tmp_line[i] && tmp_line[i + 1] && tmp_line[i + 2]
		&& (tmp_line[i] == 'S' && tmp_line[i + 1] == 'O'
			&& !ft_isalpha(tmp_line[i + 2])))
		parce_wall_textures(tmp_line + i + 3, &p->so);
	if (tmp_line[i] && tmp_line[i + 1] && tmp_line[i + 2]
		&& (tmp_line[i] == 'W' && tmp_line[i + 1] == 'E'
			&& !ft_isalpha(tmp_line[i + 2])))
		parce_wall_textures(tmp_line + i + 3, &p->we);
	if (tmp_line[i] && tmp_line[i + 1] && tmp_line[i + 2]
		&& (tmp_line[i] == 'E' && tmp_line[i + 1] == 'A'
			&& !ft_isalpha(tmp_line[i + 2])))
		parce_wall_textures(tmp_line + i + 3, &p->ea);
	return (SUCCESS);
}

int	check_colors(t_map *p)
{
	if (!p->no || !p->so || !p->we || !p->ea || p->f[0] < 0 || p->f[1] < 0
		|| p->f[2] < 0 || p->c[0] < 0 || p->c[1] < 0 || p->c[2] < 0)
		return (print_error("Uninitialized color\n"), exit(1), 1);
	if ((p->c[0] == p->f[1] && p->c[1] == p->f[0] && p->c[2] == p->f[2]))
		return (print_error("Same colors\n"), exit(1), 1);
	return (0);
}

int	parce_texture_and_colors(t_map *p, int fd)
{
	int		gnl_index;
	int		i;
	char	*tmp_line;

	gnl_index = 0;
	while (gnl_index < 6)
	{
		tmp_line = get_next_line(fd);
		if (!tmp_line)
			return (print_error("Uninitialized color\n"), exit(1), 1);
		if (tmp_line[0] == '\n')
		{
			free(tmp_line);
			continue ;
		}
		i = 0;
		parce_t_and_c_help(p, tmp_line, i);
		free(tmp_line);
		gnl_index++;
	}
	check_colors(p);
	return (SUCCESS);
}
