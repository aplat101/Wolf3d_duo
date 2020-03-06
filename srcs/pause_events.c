/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:21:10 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:21:12 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	check_options_bounds(t_data *data)
{
	if (data->fov <= 10)
		data->fov = 11;
	if (data->fov >= 180)
		data->fov = 179;
	if (data->move_speed < 0.1)
		data->move_speed = 0.1;
	if (data->move_speed >= 10)
		data->move_speed = 9.9;
	if (data->camera_speed <= 0.1)
		data->camera_speed = 0.1;
	if (data->camera_speed >= 10)
		data->camera_speed = 9.9;
}

void	arrow_clicks(t_data *data, int y)
{
	if (y > data->pause_y + 120 && y < data->pause_y + 162)
		data->move_speed += 0.1;
	else if (y > data->pause_y + 162 && y < data->pause_y + 194)
		data->move_speed -= 0.1;
	else if (y > data->pause_y + 250 && y < data->pause_y + 276)
		data->camera_speed += 0.1;
	else if (y > data->pause_y + 292 && y < data->pause_y + 312)
		data->camera_speed -= 0.1;
	else if (y > data->pause_y + 370 && y < data->pause_y + 400)
		data->fov++;
	else if (y > data->pause_y + 410 && y < data->pause_y + 435)
		data->fov--;
}

int		options_clicks(t_data *data, int x, int y)
{
	if (x >= data->pause_x + 210 && x <= data->pause_x + 517)
	{
		if (y >= HEIGHT - data->pause_y - 130
		&& y <= HEIGHT - data->pause_y - 53)
		{
			data->pause = 1;
			data->mouse_pressed = 0;
		}
		else if (y >= HEIGHT - data->pause_y - 236
		&& y <= HEIGHT - data->pause_y - 159)
		{
			data->move_speed = 5;
			data->camera_speed = 2;
			data->fov = 90;
		}
	}
	else if (x > data->pause_x + 550
	&& x < data->pause_x + 592)
		arrow_clicks(data, y);
	check_options_bounds(data);
	return (0);
}

int		texture_clicks(t_data *data, int x, int y)
{
	data->sky_offset = 0;
	data->mouse_pressed = 0;
	if (x >= data->pause_x + 80 && x <= data->pause_x + 320)
	{
		if (y >= data->pause_y + 75 && y <= data->pause_y + 315)
			return (0);
		else if (y >= data->pause_y + 375 && y <= data->pause_y + 615)
			return (2);
	}
	else if (x >= data->pause_x + 400 && x <= data->pause_x + 640)
	{
		if (y >= data->pause_y + 75 && y <= data->pause_y + 315)
			return (1);
		else if (y >= data->pause_y + 375 && y <= data->pause_y + 615)
			return (3);
	}
	return (-1);
}

int		menu_clicks(t_data *data, int x, int y)
{
	data->mouse_pressed = 0;
	if (y >= HEIGHT * 0.7 - 26 && y <= HEIGHT * 0.7 + 51)
	{
		if (x >= data->pause_x + 50 && x <= data->pause_x + 357)
			return (0);
		else if (x >= data->pause_x + PAUSE_SIZE / 2
		&& x <= data->pause_x + PAUSE_SIZE / 2 + 307)
			quit_and_close_window(data);
	}
	else if (x >= data->pause_x + 210 && x <= data->pause_x + 517)
	{
		if (y >= data->pause_y + 160 && y <= data->pause_y + 237)
			return (2);
		else if (y >= data->pause_y + 330 && y <= data->pause_y + 407)
			return (3);
	}
	return (1);
}
