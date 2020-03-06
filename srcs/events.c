/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:16:23 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 19:21:22 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			magic(t_data *data)
{
	float magic_x;
	float magic_y;

	magic_x = data->player.pos_x + data->player.dir_x * 2;
	magic_y = data->player.pos_y + data->player.dir_y * 2;
	if (magic_y > 2 && magic_x > 2 && magic_y + 2 < data->world.row_nb &&
	magic_x + 2 < data->world.line_nb)
	{
		if (data->world.map[(int)magic_x][(int)magic_y] != 0 &&
		data->world.map[(int)magic_x][(int)magic_y] != 3
		&& data->world.map[(int)magic_x][(int)magic_y] != 2)
			data->world.map[(int)magic_x][(int)magic_y] = 0;
		else if (data->world.map[(int)magic_x][(int)magic_y] != 1 &&
		data->world.map[(int)magic_x][(int)magic_y] != 3 &&
		data->world.map[(int)magic_x][(int)magic_y] != 2)
			data->world.map[(int)magic_x][(int)magic_y] = 1;
	}
}

int				key_pressed(int keycode, t_data *data)
{
	if (keycode == 49)
		magic(data);
	if (keycode == ESC)
	{
		quit_and_close_window(data);
		return (0);
	}
	if (keycode == PAUSE)
	{
		data->pause = data->pause ? 0 : 1;
		return (0);
	}
	if (keycode == W || keycode == UP)
		data->frontal = 1;
	if (keycode == S || keycode == DOWN)
		data->frontal = -1;
	if (keycode == A || keycode == LEFT)
		data->lateral = -1;
	if (keycode == D || keycode == RIGHT)
		data->lateral = 1;
	if (!data->pause)
		data->sky_offset += data->lateral * 6;
	if (abs(data->sky_offset) > data->texture.full_width[data->texturepack])
		data->sky_offset = 0;
	return (0);
}

int				key_released(int keycode, t_data *data)
{
	if (keycode == W || keycode == S || keycode == UP || keycode == DOWN)
		data->frontal = 0;
	if (keycode == A || keycode == D || keycode == LEFT || keycode == RIGHT)
		data->lateral = 0;
	return (0);
}

static int		update(t_data *data)
{
	if (!((data->frontal) && !(data->lateral)) && data->end >= 0)
		return (0);
	if (data->frontal)
		move_front(data->data_to_update);
	if (data->lateral)
		rotate(data->data_to_update);
	if (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y] == 2)
		data->data_to_update->end = 0;
	if (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y] == 3)
		data->data_to_update->end = 1;
	return (1);
}

int				check_events(t_data *data)
{
	apply_sky(data);
	if (data->end >= 0)
		apply_end_screen(data->data_to_update);
	else
	{
		if (!data->pause)
		{
			if (!update(data))
				return (0);
		}
		thread_manager(data);
		if (data->pause)
		{
			draw_menu(data);
			check_mouse_events(data);
		}
		else
			mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
									data->image.image_ptr, 0, 0);
	}
	return (1);
}
