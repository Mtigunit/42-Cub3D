/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:44:01 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:16 by ahabachi         ###   ########.fr       */
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

t_surface	*t_surface_rect(t_surface *surface, int *cords, int thickness)
{
	if (!surface || !t_surface_getbuffer(surface) || !cords)
		return (surface);
	if (thickness < 1)
		return (t_surface_fillrect(surface, cords));
	t_surface_fillrect(surface, (int []){cords[0], cords[1],
		cords[2], thickness});
	t_surface_fillrect(surface, (int []){
		cords[0],
		cords[1] + cords[3] - thickness,
		cords[2],
		thickness
	});
	t_surface_fillrect(surface, (int []){
		cords[0], cords[1] + thickness,
		thickness,
		cords[3] - 2 * thickness
	});
	t_surface_fillrect(surface, (int []){
		cords[0] + cords[2] - thickness, cords[1] + thickness,
		thickness,
		cords[3] - 2 * thickness
	});
	return (surface);
}
