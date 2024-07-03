/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   t_surface_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:55:54 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:50:12 by ahabachi         ###   ########.fr       */
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

t_surface	*t_surface_loadxpmfile(void *mlx, char *src, int len)
{
	void		*img;
	int			width;
	int			height;
	void		*buffer;
	t_surface	*surface;

	if ((len <= 4) || !src || !mlx || (src[len - 4] != '.')
		|| (src[len - 3] != 'x') || (src[len - 2] != 'p')
		|| (src[len - 1] != 'm'))
		return ((t_surface *)0);
	img = mlx_xpm_file_to_image(mlx, src, &width, &height);
	if (!img || (width < 1) || (height < 1))
		return ((t_surface *)0);
	buffer = NULL;
	surface = t_surface_new(width, height);
	if (!surface)
		return (mlx_destroy_image(mlx, img), (t_surface *)0);
	buffer = mlx_get_data_addr(img, &surface->bpp,
			&surface->line_length, &surface->endian);
	surface->mlx = mlx;
	surface->img = img;
	t_surface_setbuffer(surface, buffer);
	return (surface);
}

void	loadframes(t_surface *surface, char *file, int flen)
{
	int	i;

	i = 0;
	while ((i < surface->number) && (i < 1000))
	{
		file[flen + 0] = '/';
		file[flen + 1] = (i / 100) + '0';
		file[flen + 2] = ((i % 100) / 10) + '0';
		file[flen + 3] = ((i % 100) % 10) + '0';
		file[flen + 4] = '.';
		file[flen + 5] = 'x';
		file[flen + 6] = 'p';
		file[flen + 7] = 'm';
		file[flen + 8] = 0;
		surface->subsurfaces[i] = t_surface_loadxpmfile(surface->mlx,
				file, flen + 8);
		if (!surface->subsurfaces[i])
			break ;
		i++;
		surface->subsurfaces[i] = 0;
	}
}

t_surface	*t_surface_load_anime(void *mlx, char *s, char *file, int flen)
{
	int			number;
	t_surface	*surface;

	if (!mlx || !s || !file || (flen < 5))
		return ((t_surface *)0);
	number = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
	if (number < 1)
		return ((t_surface *)0);
	surface = t_surface_new(100, 100);
	surface->mlx = mlx;
	surface->number = number;
	surface->subsurfaces = malloc(sizeof(t_surface) * (number + 1));
	surface->subsurfaces[0] = 0;
	loadframes(surface, file, flen);
	return (t_surface_replace(surface, surface->subsurfaces[0]));
}

static inline int	t_surface_filelen(void *mlx, char *src)
{
	int	flen;

	if (!mlx || !src)
		return (-1);
	flen = 0;
	while (src[flen])
		flen++;
	while ((flen > 0) && (src[flen - 1] == '/'))
		flen--;
	if (flen < 1)
		return (-1);
	return (flen);
}

t_surface	*t_surface_load(void *mlx, char *src)
{
	int			fd;
	int			flen;
	char		*filename;
	char		info[16];
	t_surface	*surface;

	flen = t_surface_filelen(mlx, src);
	if (flen < 1)
		return ((t_surface *)0);
	filename = malloc(sizeof(char) * (flen + 16));
	if (!filename)
		return ((t_surface *)0);
	ft_memcpy(filename, src, flen);
	ft_memcpy(filename + flen, "/anime\0", 7);
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		surface = (t_surface *)0;
		if ((read(fd, info, 16) >= 3) && ('0' <= info[0] && info[0] <= '9')
			&& ('0' <= info[1] && info[1] <= '9')
			&& ('0' <= info[2] && info[2] <= '9'))
			surface = t_surface_load_anime(mlx, info, filename, flen);
		return (close(fd), free(filename), surface);
	}
	return (free(filename), t_surface_loadxpmfile(mlx, src, flen));
}
