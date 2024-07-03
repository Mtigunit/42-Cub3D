/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_cf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:09:03 by mtigunit          #+#    #+#             */
/*   Updated: 2023/04/06 10:09:24 by mtigunit         ###   ########.fr       */
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

void	parce_cf_help(const char *str, int *cf, int *i)
{
	int	j;

	if (!str || !cf || !i)
		return (print_error("pacre_cf: Invalid map 1\n"), exit(1));
	j = 0;
	skip_white_spaces(str, i);
	j = 0;
	while (ft_isdigit(str[*i + j]))
		j++;
	if (j > 3 || j <= 0)
		return (print_error("pacre_cf: Invalid map 2\n"), exit(1));
	*cf = ft_atoi(str + *i);
	*i += j;
	skip_white_spaces(str, i);
	if (str[*i] == ',')
		(*i)++;
	else if (str[*i] != ',' && str[*i])
		return (print_error("pacre_cf: Invalid map 3\n"), exit(1));
}

void	parce_cf(const char *str, int *cf)
{
	int			i;

	if (!str || !cf)
		return (print_error("pacre_cf: Invalid map 0\n"), exit(1));
	i = 0;
	parce_cf_help(str, &cf[0], &i);
	parce_cf_help(str, &cf[1], &i);
	parce_cf_help(str, &cf[2], &i);
	if (str[i])
		return (print_error("pacre_cf: Invalid map 3\n"), exit(1));
	if ((cf[0] < 0 || cf[0] > 255) || (cf[1] < 0 || cf[1] > 255)
		|| (cf[2] < 0 || cf[2] > 255))
		return (print_error("pacre_cf: Invalid color range\n"), exit(1));
}
