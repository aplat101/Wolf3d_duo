/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 07:08:26 by widrye            #+#    #+#             */
/*   Updated: 2020/02/17 21:26:35 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		rotate(t_data *data)
{
	float old_dir_x;
	float old_plane_x;
	float speed;

	speed = data->camera_speed / 100;
	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.screen_x;
	if (data->lateral == 1 && speed > 0)
		speed *= -1;
	data->player.dir_x = data->player.dir_x * cos(speed) -
	data->player.dir_y * sin(speed);
	data->player.dir_y = old_dir_x * sin(speed) +
	data->player.dir_y * cos(speed);
	data->player.screen_x = data->player.screen_x * cos(speed) -
	data->player.screen_y * sin(speed);
	data->player.screen_y = old_plane_x * sin(speed) +
	data->player.screen_y * cos(speed);
}

void		collision_check(t_data *data, float hit_dist,
float move_pos_x, float move_pos_y)
{
	float hitx;
	float hity;

	hitx = data->player.dir_x * hit_dist;
	hity = data->player.dir_y * hit_dist;
	if (data->frontal == -1)
	{
		hitx *= -1;
		hity *= -1;
	}
	hitx += data->player.pos_x;
	hity += data->player.pos_y;
	if (data->world.map[(int)hitx][(int)hity] != 0 && data->world.map[(int)hitx]
	[(int)hity] != 3 && data->world.map[(int)hitx][(int)hity] != 2)
	{
		if (data->world.map[(int)hitx][(int)data->player.pos_y] == 0)
			data->player.pos_x += move_pos_x;
		else if (data->world.map[(int)data->player.pos_x][(int)hity] == 0)
			data->player.pos_y += move_pos_y;
	}
	else
	{
		data->player.pos_x += move_pos_x;
		data->player.pos_y += move_pos_y;
	}
}

void		move_front(t_data *data)
{
	float move_pos_x;
	float move_pos_y;
	float speed;

	speed = data->move_speed / 100;
	move_pos_x = data->player.dir_x * (data->move_speed / 100);
	move_pos_y = data->player.dir_y * (data->move_speed / 100);
	if (data->frontal == -1)
	{
		move_pos_x *= -1;
		move_pos_y *= -1;
	}
	collision_check(data, speed * 5, move_pos_x, move_pos_y);
}
