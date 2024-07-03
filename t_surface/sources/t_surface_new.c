/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:43:43 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:14 by ahabachi         ###   ########.fr       */
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

t_surface	*t_surface_new(int width, int height)
{
	t_surface	*surface;

	surface = malloc(sizeof(t_surface));
	if (surface)
	{
		surface->width = width;
		surface->height = height;
		surface->color = 0;
		surface->data = 0;
		surface->number = 0;
		surface->index = 0;
		surface->lastframe = ft_timestamp(0);
		surface->delay = 100;
		surface->loop = 0;
		surface->subsurfaces = 0;
		surface->mlx = 0;
		surface->img = 0;
		surface->endian = 0;
		surface->bpp = 32;
		surface->line_length = (surface->bpp / 8) * width;
		t_surface_setbuffer(surface, NULL);
	}
	return (surface);
}
