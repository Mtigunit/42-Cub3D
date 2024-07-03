/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_cub3d_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:51:52 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:33 by ahabachi         ###   ########.fr       */
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

int	ft_keyboard_events(int key, t_cub3d *cub)
{
	if (!cub)
		return (0);
	if (key == KEYCODE_H)
		cub->hidemap = !cub->hidemap;
	if (key == KEYCODE_ESC)
		return (t_cub3d_stop(cub));
	if (key == KEYCODE_SPACE)
		cub->pause = !cub->pause;
	if (cub->pause)
		return (0);
	if (t_cub3d_loading(cub))
		return (0);
	cub->keycode = key;
	t_cub3d_events(cub);
	return (0);
}

int	t_cub3d_onmousemove(int x, int y, t_cub3d *cub)
{
	int	dx;

	(void) y;
	if (!cub || cub->pause)
		return (0);
	dx = x - cub->mouse_pressed_x;
	if (0 <= cub->mouse_pressed_x && cub->mouse_pressed_x < cub->width)
	{
		if (0 <= cub->mouse_pressed_y && cub->mouse_pressed_y < cub->height)
		{
			if (dx < -20)
			{
				cub->keycode = KEYCODE_ARROW_RIGHT;
				cub->mouse_pressed_x = x;
				t_cub3d_events(cub);
			}
			else if (dx > 20)
			{
				cub->keycode = KEYCODE_ARROW_LEFT;
				cub->mouse_pressed_x = x;
				t_cub3d_events(cub);
			}
		}
	}
	return (0);
}

int	t_cub3d_onmouseup(int button, int x, int y, t_cub3d *cub)
{
	(void) button;
	(void) x;
	(void) y;
	if (!cub || cub->pause)
		return (0);
	cub->mouse_pressed_x = -1;
	cub->mouse_pressed_y = -1;
	return (0);
}

int	t_cub3d_onmousedown(int button, int x, int y, t_cub3d *cub)
{
	if (!cub || cub->pause)
		return (0);
	cub->mouse_pressed_x = -1;
	cub->mouse_pressed_y = -1;
	cub->keycode = -1;
	if (button == 5)
	{
		cub->keycode = KEYCODE_ARROW_UP;
		t_cub3d_events(cub);
	}
	else if (button == 4)
	{
		cub->keycode = KEYCODE_ARROW_DOWN;
		t_cub3d_events(cub);
	}
	else if (button == 1)
	{
		cub->mouse_pressed_x = x;
		cub->mouse_pressed_y = y;
	}
	return (0);
}

t_cub3d	*t_cub3d_events(t_cub3d *cub)
{
	if (!cub || cub->pause)
		return (cub);
	ft_timestamp(cub->width / 11);
	t_player_update(cub->player);
	t_cub3d_update(cub);
	t_cub3d_draw(cub);
	return (cub);
}
