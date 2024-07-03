/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_setpixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:43:43 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:32 by mtigunit         ###   ########.fr       */
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

t_surface	*t_surface_setpixel(t_surface *surface, int x, int y, int color)
{
	char	*dst;

	if (!surface || !t_surface_getbuffer(surface))
		return (surface);
	if ((x < 0) || (x >= surface->width) || (y < 0) || (y >= surface->height))
		return (surface);
	dst = t_surface_getbuffer(surface)
		+ (y * surface->line_length + x * (surface->bpp / 8));
	*(unsigned int *)dst = color;
	return (surface);
}
