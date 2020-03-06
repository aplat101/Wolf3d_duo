/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:17:54 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 19:12:16 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		init_rays_and_player(t_rays *rays, t_player *player)
{
	rays->dir_x = 0;
	rays->dir_y = 0;
	rays->wall = 0;
	rays->pos_x = 0;
	rays->pos_y = 0;
	rays->side = 0;
	player->dir_x = -1;
	player->dir_y = 0.00001;
	player->screen_x = 0;
	player->screen_y = 0.6;
	player->cam_x = -1;
}

static void		init_world(t_world *world, char **map)
{
	world->x = -1;
	world->line_nb = ft_line_nb(map);
	world->row_nb = find_biggest_line(map);
	if (world->line_nb <= 5 || world->row_nb <= 5)
	{
		world->line_nb = 6;
		world->row_nb = 6;
		world->map = create_basic_map();
	}
	else
	{
		world->line_nb += 2;
		world->row_nb += 2;
		world->map = init_tab_2d_int(world->line_nb, world->row_nb + 2);
		if (!stock_points(world, map))
		{
			world->line_nb = 6;
			world->row_nb = 6;
			world->map = create_basic_map();
			return ;
		}
		secure_map(world, map);
	}
}

void			init_struct_values(t_data *data)
{
	data->move_speed = 5;
	data->camera_speed = 2;
	data->mouse_pressed = 0;
	data->fov = 90;
	data->pause_x = (WIDTH - PAUSE_SIZE) / 2;
	data->pause_y = (HEIGHT - PAUSE_SIZE) / 2;
	data->pause = 0;
	data->sky_offset = 0;
	data->texturepack = 0;
	data->data_to_update = data;
}

int				init_struct(t_data *data)
{
	t_player		player;
	t_rays			rays;
	t_world			world;
	t_texture		texture;

	init_world(&world, data->map);
	if (pthread_mutex_init(&data->lock, NULL))
		return (-1);
	if (load_xpm(&texture, data->mlx_ptr) == -1)
		return (-1);
	init_rays_and_player(&rays, &player);
	data->thread_n = 0;
	data->player = player;
	data->world = world;
	data->rays = rays;
	data->texture = texture;
	data->frontal = 0;
	data->lateral = 0;
	data->end = -1;
	return (0);
}
