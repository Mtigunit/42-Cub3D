/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:54:51 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:52 by ahabachi         ###   ########.fr       */
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

void	t_surface_update(t_surface *surface)
{
	if (!surface || (surface->number < 1) || !surface->subsurfaces)
		return ;
	if ((surface->index < 0) || (surface->index >= surface->number))
		return ;
	if (surface->lastframe <= 0)
		surface->lastframe = 0;
	if ((ft_timestamp(0) - surface->lastframe) < surface->delay)
		return ;
	t_surface_replace(surface, surface->subsurfaces[surface->index]);
	if (surface->subsurfaces[surface->index])
	{
		surface->index++;
		if (surface->index >= surface->number)
		{
			surface->loop++;
			surface->index = 0;
		}
	}
	else
	{
		surface->loop++;
		surface->index = 0;
	}
	surface->lastframe = ft_timestamp(0);
}
