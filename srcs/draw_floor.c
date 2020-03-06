/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:22:38 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 13:59:22 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void					pixelit(t_data *data, int64_t y, int64_t x, int rgba)
{
	if (y < 0 || x < 0 || y >= HEIGHT || x >= WIDTH)
		return ;
	data->image.image_str[(y * WIDTH) + x] = rgba;
}

static void				pick_tp_colors(int tp, t_vector *c)
{
	if (tp == 0)
	{
		c->x = GREEN_GRASS;
		c->y = GREEN_DARK;
		return ;
	}
	else if (tp == 1)
	{
		c->x = BROWN_DARK;
		c->y = BROWN_LIGHT;
		return ;
	}
	else if (tp == 2)
	{
		c->x = BROWN_DARK;
		c->y = RED_DARK;
		return ;
	}
	else
	{
		c->x = GREY_DARK;
		c->y = BLUE_DARK;
		return ;
	}
}

void					draw_floor(t_data *data)
{
	int			y;
	t_vector	color;

	pick_tp_colors(data->texturepack, &color);
	y = data->world.line_pos[1][data->world.x] - 1;
	while (y < HEIGHT)
	{
		pixelit(data, y, data->world.x,
		get_gradient_color(HEIGHT - data->world.line_pos[1]
		[data->world.x], y - data->world.line_pos[1][data->world.x],
		color.x, color.y));
		y++;
	}
}
