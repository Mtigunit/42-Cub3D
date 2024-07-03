/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_cub3d_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:51:14 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:47 by ahabachi         ###   ########.fr       */
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

int	t_cub3d_loading(t_cub3d *cub)
{
	if (cub && cub->image && cub->loading && (cub->loading->loop < 1))
	{
		t_surface_copy(
			cub->image, cub->loading,
			(int []){0, 0, cub->image->width, cub->image->height},
			(int []){0, 0, cub->loading->width, cub->loading->height}
			);
		if (cub->loading->loop >= 1)
			cub->loading = t_surface_del(cub->loading);
		return (1);
	}
	return (0);
}
