#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 14:12:43 by ahabachi          #+#    #+#              #
#    Updated: 2023/04/08 15:46:53 by ahabachi         ###   ########.fr        #
#                                                                              #
#  **************************************************************************  #
#                                                                              #
#   █████████            ██████████         ██████████         ██████████      #
#   ██     ██                    ██                 ██         ██      ██      #
#          ██                    ██                 ██         ██      ██      #
#          ██                    ██                 ██                 ██      #
#          ██            ██████████         ██████████                 ██      #
#          ██                    ██                 ██                 ██      #
#          ██                    ██                 ██                 ██      #
#          ██                    ██                 ██                 ██      #
#       ████████         ██████████         ██████████                 ██      #
#                                                                              #
#  **************************************************************************  #

CUB3D_SOURCES	=	t_cub3d/sources/t_cub3d_clear.c\
					t_cub3d/sources/t_cub3d_draw.c\
					t_cub3d/sources/t_cub3d_events.c\
					t_cub3d/sources/t_cub3d_init.c\
					t_cub3d/sources/t_cub3d_loading.c\
					t_cub3d/sources/t_cub3d_new.c\
					t_cub3d/sources/t_cub3d_run.c\
					t_cub3d/sources/t_cub3d_start.c\
					t_cub3d/sources/t_cub3d_stop.c\
					t_cub3d/sources/t_cub3d_update.c\
					t_map/sources/ft_free_struct.c\
					t_map/sources/check_first_column.c\
					t_map/sources/check_valid_extension.c\
					t_map/sources/check_wall_line.c\
					t_map/sources/copy_map.c\
					t_map/sources/get_map.c\
					t_map/sources/init_map.c\
					t_map/sources/open_file.c\
					t_map/sources/parce_cf.c\
					t_map/sources/parce_door.c\
					t_map/sources/parce_map.c\
					t_map/sources/parce_texture_and_colors.c\
					t_map/sources/parce_wall_textures.c\
					t_map/sources/parce_zero.c\
					t_map/sources/print_error.c\
					t_map/sources/skip_white_spaces.c\
					t_map/sources/t_map.c\
					t_map/sources/t_map_new.c\
					t_map/sources/t_map_draw.c\
					t_map/sources/t_map_init.c\
					t_map/sources/texture_extension.c\
					t_map/sources/t_map_sprite_index.c\
					t_player/sources/t_player_new.c\
					t_player/sources/t_player_init.c\
					t_player/sources/t_player_movement.c\
					t_player/sources/t_player_update.c\
					t_raycasting/sources/t_raycasting_view.c\
					t_raycasting/sources/t_raycasting_close_door.c\
					t_raycasting/sources/t_raycasting_draw.c\
					t_raycasting/sources/t_raycasting_intersection.c\
					t_raycasting/sources/t_raycasting_object_draw.c\
					t_raycasting/sources/t_raycasting_object_reset.c\
					t_raycasting/sources/t_raycasting_object_update.c\
					t_raycasting/sources/t_raycasting_project.c\
					t_raycasting/sources/t_raycasting_update.c\
					t_raycasting/sources/t_raycasting_new.c\
					t_surface/sources/t_surface_clear.c\
					t_surface/sources/t_surface_copy.c\
					t_surface/sources/t_surface_del.c\
					t_surface/sources/t_surface_fillrect.c\
					t_surface/sources/t_surface_fullcopy.c\
					t_surface/sources/t_surface_getbuffer.c\
					t_surface/sources/t_surface_getpixel.c\
					t_surface/sources/t_surface_load.c\
					t_surface/sources/t_surface_new.c\
					t_surface/sources/t_surface_rect.c\
					t_surface/sources/t_surface_replace.c\
					t_surface/sources/t_surface_setbuffer.c\
					t_surface/sources/t_surface_setcolor.c\
					t_surface/sources/t_surface_setpixel.c\
					t_surface/sources/t_surface_update.c\
					main.c

CUB3D_OBJECTS	=	$(CUB3D_SOURCES:.c=.o)

CUB3D_HEADERS	=	cub3d.h

CUB3D_INCLUDE	=	-I./

NAME			=	cub3D

CFLAGS			=	-Wall -Wextra -Werror

%.o: %.c $(CUB3D_HEADERS)
	cc $(CFLAGS) $(CUB3D_INCLUDE) -c $< -o $@

$(NAME): $(CUB3D_OBJECTS) $(CUB3D_HEADERS)
	@make bonus -C libft
	cc $(CFLAGS) -L./libft/ -lft  -lmlx -framework OpenGL -framework AppKit -o $(NAME) ${CUB3D_OBJECTS}

all: $(NAME)

clean:
	make clean -C libft
	rm -rf $(CUB3D_OBJECTS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

bonus: $(NAME)

run: all
	./$(NAME) assets/maps/map.cub
