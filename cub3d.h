/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:33:06 by ahabachi          #+#    #+#             */
/*   Updated: 2023/04/08 16:46:08 by ahabachi         ###   ########.fr       */
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

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_surface	t_surface;
typedef struct s_raycasting	t_raycasting;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef float				t_real;
typedef struct s_cub3d		t_cub3d;

# define MIN_DOOR_DISTANCE			1.8

# define KEYCODE_ARROW_UP			126
# define KEYCODE_ARROW_DOWN			125
# define KEYCODE_ARROW_LEFT			123
# define KEYCODE_ARROW_RIGHT		124
# define KEYCODE_ESC				53
# define KEYCODE_W					13
# define KEYCODE_A					0
# define KEYCODE_S					1
# define KEYCODE_D					2
# define KEYCODE_PLUS				69
# define KEYCODE_MINUS				78
# define KEYCODE_SPACE				49
# define KEYCODE_H					4

# define EVENT_ON_KEYDOWN			2
# define EVENT_ON_KEYUP				3
# define EVENT_ON_MOUSEDOWN			4
# define EVENT_ON_MOUSEUP			5
# define EVENT_ON_MOUSEMOVE			6
# define EVENT_ON_EXPOSE			12
# define EVENT_ON_DESTROY			17
# define DEFAULT_WINDOW_WIDTH		1600
# define DEFAULT_WINDOW_HEIGHT		900

# define DEFAULT_PLAYER_POS_X		1.5
# define DEFAULT_PLAYER_POS_Y		5.0
# define DEFAULT_PLAYER_ANGLE		0.0
# define DEFAULT_PLAYER_SPEED		0.2
# define DEFAULT_PLAYER_ROT_SPEED	0.04
# define DEFAULT_PLAYER_MAXSPEED	10
# define PLAYER_ACCELERATION		0.05

# define DEFAULT_FRONT_WALL_COLOR	0x000000FF
# define DEFAULT_BACK_WALL_COLOR	0x00FF00FF
# define DEFAULT_LEFT_WALL_COLOR	0x00FF0000
# define DEFAULT_RIGHT_WALL_COLOR	0x0000FF00
# define DEFAULT_DOOR_COLOR			0x00FFFF00

# define VERTICAL	31321
# define HORIZONTAL	45125

# define MAX_SPRITES_NUMBER			26
# define T_SURFACE_H 				20230327
# define TRANSPARENT				0xFF000000

# ifndef FAILURE
#  define FAILURE 1
# endif //!FAILURE

# ifndef SUCCESS
#  define SUCCESS 0
# endif //!SUCCESS

typedef struct s_surface
{
	int					width;
	int					height;
	int					color;
	char				*data;
	int					bpp;
	int					line_length;
	int					endian;
	int					number;
	int					index;
	long long			lastframe;
	long long			delay;
	long long			loop;
	struct s_surface	**subsurfaces;
	void				*mlx;
	void				*img;
}	t_surface;

typedef struct s_cub3d
{
	int				sprites_number;
	t_surface		*sprites[MAX_SPRITES_NUMBER];
	int				width;
	int				height;
	void			*img;
	void			*mlx;
	void			*win;
	char			*title;
	int				keycode;
	t_player		*player;
	t_surface		*image;
	t_map			*map;
	t_raycasting	*raycasting;
	int				mouse_pressed_y;
	int				mouse_pressed_x;
	t_surface		*no_texture;
	t_surface		*so_texture;
	t_surface		*we_texture;
	t_surface		*ea_texture;
	t_surface		*loading;
	t_surface		*door;
	int				pause;
	int				hidemap;
	t_real			fov;
	t_real			num_rays;
	t_real			delta_angle;
	t_real			screen_dist;
	t_real			scale;
}	t_cub3d;

typedef struct s_map
{
	t_real	start_x;
	t_real	start_y;
	int		c[3];
	int		f[3];
	int		player_x;
	int		player_y;
	t_cub3d	*cub;
	int		width;
	int		height;
	char	**data;
	int		ceiling_color;
	int		floor_color;
	char	*so;
	char	*no;
	char	*ea;
	char	*we;
	char	*floor;
	char	*ceiling;
	int		scale;
	int		size;
}	t_map;

typedef struct s_player
{
	t_cub3d	*cub;
	t_real	x;
	t_real	y;
	t_real	angle;
	t_real	speed;
	t_real	rotation_speed;
	int		size;
}	t_player;

typedef struct s_raycasting_object
{
	int			start_wall;
	int			ray_start;
	t_real		angle_start;
	t_real		start_x;
	t_real		start_y;
	t_real		start_distance;
	t_real		mid_x;
	t_real		mid_y;
	t_real		mid_distance;
	t_real		end_x;
	t_real		end_y;
	t_real		end_distance;
	t_real		x;
	t_real		y;
	t_real		width;
	t_real		height;
	t_surface	*texture;
	char		identifier;
}	t_raycasting_object;

typedef struct s_raycasting
{
	t_real				x;
	t_real				y;
	t_real				dx;
	t_real				dy;
	t_real				dot_product;
	int					number;
	t_cub3d				*cub;
	t_real				angle;
	t_real				distance;
	t_real				opposite;
	t_real				adjacent;
	t_real				tangente;
	t_surface			*texture;
	t_real				projected_height;
	t_real				inter_x;
	t_real				inter_y;
	int					wallcolor;
	int					texture_offset;
	int					wall;
	t_raycasting_object	*object;
	char				identifier;
}	t_raycasting;

t_real			ft_limit(t_real x);
t_raycasting	*t_raycasting_new(t_cub3d *cub);
t_player		*t_player_new(t_cub3d *cub);
int				ft_keyboard_events(int key, t_cub3d *cub);
void			t_surface_copy(t_surface *dst, t_surface *src,
					int *dcords, int *scords);
t_surface		*t_surface_del(t_surface *surface);
t_surface		*t_surface_fullcopy(t_surface *dest, t_surface *src);
char			*t_surface_getbuffer(t_surface *surface);
int				t_surface_getpixel(t_surface *surface, int x, int y);
t_surface		*t_surface_new(int width, int height);
int				t_surface_setcolor(t_surface *surface, int color);
t_surface		*t_surface_setpixel(t_surface *surface, int x,
					int y, int color);
void			t_surface_update(t_surface *surface);

t_cub3d			*t_cub3d_clear(t_cub3d *cub);
t_cub3d			*t_cub3d_draw(t_cub3d *cub);
int				t_cub3d_onmousemove(int x, int y, t_cub3d *cub);
int				t_cub3d_onmouseup(int button, int x, int y, t_cub3d *cub);
int				t_cub3d_onmousedown(int button, int x, int y, t_cub3d *cub);
t_cub3d			*t_cub3d_events(t_cub3d *cub);
t_cub3d			*t_cub3d_init_textures(t_cub3d *cub);
void			t_cub3d_initwindow(t_cub3d *cub);
t_cub3d			*t_cub3d_init(t_cub3d *cub);
int				t_cub3d_loading(t_cub3d *cub);
int				t_map_sprite_index(char c);
t_cub3d			*t_cub3d_new(char *filename, int width, int height);
t_cub3d			*t_cub3d_run(t_cub3d *cub);
int				t_cub3d_usage(int argc, char **argv);
int				t_cub3d_start(int argc, char **argv);
int				t_cub3d_stop(t_cub3d *cub);
t_cub3d			*t_cub3d_update(t_cub3d *cub);
int				check_first_column(char **map, int y);
void			check_valid_extension(char *path);
int				check_wall_line(const char *str);
void			copy_map(t_map *p, char **map);
char			**get_map(char **tmp_map, char *tmp_line, int fd, int *map_len);
int				init_map(t_map *p, char *path);
t_map			*ft_free_struct(t_map *p);
int				open_file(char *path);
void			parce_cf_help(const char *str, int *cf, int *i);
void			parce_cf(const char *str, int *cf);
void			parce_door(char **map, int x, int y, int map_len);
char			**parce_map(t_map *p, char **map, int map_len);
int				parce_texture_and_colors(t_map *p, int fd);
int				parce_wall_textures(const char *str, char **identifier);
int				parce_zero(char **map, int x, int y, int map_len);
void			print_error(const char *error_msg);
void			skip_white_spaces(const char *str, int *i);
int				t_map_getelement(t_map *map, int x, int y);
int				t_map_setelement(t_map *map, int x, int y, char c);
int				t_map_isempty(t_map *map, int x, int y);
int				t_map_issprite(t_map *map, int x, int y);
int				t_map_isfilled(t_map *map, int x, int y);
t_map			*t_map_new(char *filename);
t_map			*t_map_draw(t_map *map);
void			t_map_init(t_map *map, char *filename);
void			texture_extension(const char *path);
void			usage(void);
t_player		*t_player_init(t_player *player, t_cub3d *cub);
t_player		*t_player_collision(t_player *player, t_real dx, t_real dy);
t_player		*t_player_move_left(t_player *player);
t_player		*t_player_move_right(t_player *player);
t_player		*t_player_move_forward(t_player *player);
t_player		*t_player_move_backward(t_player *player);
t_player		*t_player_movement(t_player *player);
t_player		*t_player_open_door(t_player *player);
t_player		*t_player_update(t_player *player);
void			t_raycasting_close_door(t_map *map, int x, int y,
					float distance);
t_raycasting	*t_raycasting_draw(t_raycasting *ray);
t_real			t_raycasting_intersection(t_raycasting *ray);
int				t_raycasting_object_init(t_raycasting *ray);
void			t_raycasting_object_draw(t_raycasting *ray);
void			t_raycasting_object_reset(t_raycasting_object *object);
void			t_raycasting_object_enter(t_raycasting *ray);
void			t_raycasting_object_update(t_raycasting *ray);
int				t_raycasting_front_view(t_raycasting *ray);
int				t_raycasting_back_view(t_raycasting *ray);
int				t_raycasting_left_view(t_raycasting *ray);
int				t_raycasting_right_view(t_raycasting *ray);
int				t_raycasting_view(t_raycasting *ray, int x, int y);
t_raycasting	*t_raycasting_project(t_raycasting *ray);
t_raycasting	*t_raycasting_update(t_raycasting *ray);
t_surface		*t_surface_clear(t_surface *surface, int color);
t_surface		*t_surface_fillrect(t_surface *surface, int *cords);
char			*t_surface_getbuffer(t_surface *surface);
t_surface		*t_surface_load(void *mlx, char *src);
t_surface		*t_surface_rect(t_surface *surface, int *cords, int thickness);
t_surface		*t_surface_replace(t_surface *dest, t_surface *src);
t_surface		*t_surface_setbuffer(t_surface *surface, void *buffer);

#endif // !CUB3D_H
