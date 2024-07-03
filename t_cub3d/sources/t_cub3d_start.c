/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_cub3d_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:35:30 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:54 by ahabachi         ###   ########.fr       */
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

int	t_cub3d_usage(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	return (0);
}

int	t_cub3d_start(int argc, char **argv)
{
	t_cub3d	*cub;

	if (argc != 2)
		return (t_cub3d_usage(argc, argv));
	cub = t_cub3d_new(argv[1], 800 * 2, 450 * 2);
	t_cub3d_init(cub);
	t_cub3d_run(cub);
	t_cub3d_stop(cub);
	return (0);
}
