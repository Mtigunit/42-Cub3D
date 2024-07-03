/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:12 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:56 by mtigunit         ###   ########.fr       */
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

void	t_surface_copy(t_surface *dst, t_surface *src, int *dcords, int *scords)
{
	int		i;
	int		j;
	int		color;
	float	rx;
	float	ry;

	if (!dst || !src || !dcords || !scords || dcords[2] < 1 || dcords[3] < 1)
		return ;
	rx = (scords[2] * 1.0 / dcords[2]);
	ry = (scords[3] * 1.0 / dcords[3]);
	i = 0;
	while ((i < dcords[2]) && (dcords[0] + i < dst->width))
	{
		j = 0;
		while ((j < dcords[3]) && (dcords[1] + j < dst->height))
		{
			color = t_surface_getpixel(
					src, scords[0] + i * rx, scords[1] + j * ry);
			if ((unsigned int) color < TRANSPARENT)
				t_surface_setpixel(dst, dcords[0] + i, dcords[1] + j, color);
			j++;
		}
		i++;
	}
}
