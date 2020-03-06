/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:26:01 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:26:04 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_STRUCT_H
# define WOLF_STRUCT_H

# include "wolf_define.h"
# include "wolf.h"
# include <pthread.h>

typedef struct		s_vector
{
	float					x;
	float					y;
}					t_vector;

typedef struct		s_image
{
	int						*image_str;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	void					*image_ptr;
}					t_image;

typedef struct		s_player
{
	float					pos_x;
	float					pos_y;
	float					dir_x;
	float					dir_y;
	float					screen_x;
	float					screen_y;
	float					cam_x;
}					t_player;

typedef struct		s_rays
{
	float					dir_x;
	float					dir_y;
	int						pos_x;
	int						pos_y;
	float					len_x;
	float					len_y;
	int						side;
	float					dist_x;
	float					dist_y;
	int						inc_x;
	int						inc_y;
	int						wall;
	float					dist_from_wall;
}					t_rays;

typedef struct		s_texture
{
	t_image					wall[17];
	t_image					texturepacks[4];
	t_image					end_screen[2];
	t_image					sky[4];
	t_image					pause_box;
	t_image					pause_button;
	t_image					options_box;
	t_image					pause_arrows[2];
	float					map_x;
	float					y;
	float					x;
	int						size;
	int						icon_w;
	int						icon_h;
	int						full_width[4];
	int						full_height[4];
	int						i;
}					t_texture;

typedef struct		s_world
{
	int				**map;
	float			line_height;
	int				line_pos[2][WIDTH];
	int				x;
	int				line_nb;
	int				row_nb;
}					t_world;

typedef struct		s_segment
{
	t_vector				p1;
	t_vector				p2;
	t_vector				p;
	int						d;
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						e;
	int						e2;
}					t_segment;

typedef struct		s_data
{
	int						thread_n;
	pthread_mutex_t			lock;
	t_image					image;
	t_player				player;
	t_rays					rays;
	t_world					world;
	t_texture				texture;
	float					move_speed;
	float					camera_speed;
	float					fov;
	float					pause_y;
	float					pause_x;
	int						mouse_x;
	int						mouse_y;
	int						mouse_pressed;
	int						frontal;
	int						lateral;
	int						end;
	int						pause;
	int						texturepack;
	int						sky_offset;
	void					*window_ptr;
	void					*mlx_ptr;
	char					**map;
	struct s_data			*data_to_update;
}					t_data;

#endif
