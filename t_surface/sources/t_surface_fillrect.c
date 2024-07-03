/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_fillrect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:44:01 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:01 by ahabachi         ###   ########.fr       */
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

t_surface	*t_surface_fillrect(t_surface *surface, int *cords)
{
	int	i;
	int	j;

	if (!surface || !t_surface_getbuffer(surface) || !cords)
		return (surface);
	i = 0;
	while ((i < cords[2]) && (i < surface->width - cords[0]))
	{
		j = 0;
		while ((j < cords[3]) && (j < surface->height - cords[1]))
		{
			t_surface_setpixel(surface, cords[0] + i, cords[1] + j,
				surface->color);
			j++;
		}
		i++;
	}
	return (surface);
}
