/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:30:41 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:59 by ahabachi         ###   ########.fr       */
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

t_surface	*t_surface_del(t_surface *surface)
{
	int	i;

	if (!surface)
		return ((t_surface *)0);
	if (surface->subsurfaces && (surface->number >= 1))
	{
		i = 0;
		surface->img = 0;
		while (i < surface->number)
			t_surface_del(surface->subsurfaces[i++]);
		free(surface->subsurfaces);
		surface->subsurfaces = 0;
		surface->number = 0;
	}
	if (surface->mlx && surface->img)
		mlx_destroy_image(surface->mlx, surface->img);
	return (free(surface), (t_surface *)0);
}
