/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_getpixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:28:40 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:08 by mtigunit         ###   ########.fr       */
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

int	t_surface_getpixel(t_surface *surface, int x, int y)
{
	char	*dst;

	if (!surface || !t_surface_getbuffer(surface))
		return (TRANSPARENT);
	if ((x < 0) || (x >= surface->width) || (y < 0) || (y >= surface->height))
		return (TRANSPARENT);
	dst = t_surface_getbuffer(surface)
		+ (y * surface->line_length + x * (surface->bpp / 8));
	return (*(unsigned int *)dst);
}
