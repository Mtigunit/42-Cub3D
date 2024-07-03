/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_raycasting_object_reset.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:49:14 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:49:40 by mtigunit         ###   ########.fr       */
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

void	t_raycasting_object_reset(t_raycasting_object *object)
{
	if (object)
	{
		object->start_wall = -1;
		object->ray_start = -1;
		object->angle_start = -1.0;
		object->start_x = -1.0;
		object->start_y = -1.0;
		object->start_distance = -1.0;
		object->mid_x = -1.0;
		object->mid_y = -1.0;
		object->mid_distance = -1.0;
		object->end_x = -1.0;
		object->end_y = -1.0;
		object->end_distance = -1.0;
	}
}
