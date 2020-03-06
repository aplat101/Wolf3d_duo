/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:15:50 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:16:01 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		texture_buttons(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
	data->texture.pause_box.image_ptr, data->pause_x, data->pause_y);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
	data->texture.texturepacks[0].image_ptr,
	data->pause_x + 80, data->pause_y + 75);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
	data->texture.texturepacks[1].image_ptr,
	data->pause_x + 400, data->pause_y + 75);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
	data->texture.texturepacks[2].image_ptr,
	data->pause_x + 80, data->pause_y + 375);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
	data->texture.texturepacks[3].image_ptr,
	data->pause_x + 400, data->pause_y + 375);
}

static void		arrow_buttons(t_data *data)
{
	int i;

	i = 1;
	while (i++ < 8)
	{
		i++;
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->texture.pause_arrows[1].image_ptr,
		data->pause_x + 550, data->pause_y + (i++ * 40));
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->texture.pause_arrows[0].image_ptr,
		data->pause_x + 550, data->pause_y + (i * 40));
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->texture.options_box.image_ptr,
		data->pause_x + 290, data->pause_y + (i * 40) - 32);
	}
}

void			options_buttons(t_data *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr,
	d->texture.pause_box.image_ptr, d->pause_x, d->pause_y);
	arrow_buttons(d);
	mlx_string_put(d->mlx_ptr, d->window_ptr, d->pause_x + 120,
	d->pause_y + 150, WHITE, "MOVE SPEED :");
	mlx_string_put(d->mlx_ptr, d->window_ptr, d->pause_x + 380,
	d->pause_y + 154, WHITE, ft_itoa(d->move_speed * 10));
	mlx_string_put(d->mlx_ptr, d->window_ptr, d->pause_x + 80,
	d->pause_y + 270, WHITE, "ROTATION SPEED :");
	mlx_string_put(d->mlx_ptr, d->window_ptr, d->pause_x + 380,
	d->pause_y + 274, WHITE, ft_itoa(d->camera_speed * 10));
	mlx_string_put(d->mlx_ptr, d->window_ptr, d->pause_x + 90,
	d->pause_y + 390, WHITE, "FIELD OF VIEW :");
	mlx_string_put(d->mlx_ptr, d->window_ptr, d->pause_x + 380,
	d->pause_y + 394, WHITE, ft_itoa(d->fov));
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr,
	d->texture.pause_button.image_ptr, d->pause_x + 210,
	HEIGHT - d->pause_y - 156);
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr,
	d->texture.pause_button.image_ptr, d->pause_x + 210,
	HEIGHT - d->pause_y - 236);
	mlx_string_put(d->mlx_ptr, d->window_ptr, WIDTH / 2 - 16,
	HEIGHT - d->pause_y - 210, BLACK, "RESET");
	mlx_string_put(d->mlx_ptr, d->window_ptr, WIDTH / 2 - 12,
	HEIGHT - d->pause_y - 130, BLACK, "APPLY");
}

static void		menu_buttons(t_data *d)
{
	mlx_put_image_to_window(d->mlx_ptr,
	d->window_ptr, d->image.image_ptr, 0, 0);
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr, d->texture.
	pause_box.image_ptr, d->pause_x, d->pause_y);
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr, d->texture.
	pause_button.image_ptr, d->pause_x + 210, d->pause_y + 160);
	mlx_string_put(d->mlx_ptr, d->window_ptr,
	WIDTH / 2 - 26, d->pause_y + 190, BLACK, "OPTIONS");
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr, d->texture.
	pause_button.image_ptr, d->pause_x + 210, d->pause_y + 333);
	mlx_string_put(d->mlx_ptr, d->window_ptr,
	WIDTH / 2 - 30, HEIGHT / 2, BLACK, "TEXTURES");
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr,
	d->texture.pause_button.image_ptr, d->pause_x + 50, HEIGHT * 0.7 - 26);
	mlx_string_put(d->mlx_ptr, d->window_ptr,
	d->pause_x + (PAUSE_SIZE / 4), HEIGHT * 0.7, BLACK, "BACK");
	mlx_put_image_to_window(d->mlx_ptr, d->window_ptr,
	d->texture.pause_button.image_ptr,
	d->pause_x + PAUSE_SIZE / 2, HEIGHT * 0.7 - 26);
	mlx_string_put(d->mlx_ptr, d->window_ptr,
	d->pause_x + (PAUSE_SIZE / 2) + 142, HEIGHT * 0.7, BLACK, "QUIT");
}

void			draw_menu(t_data *data)
{
	shade_area(data, 0, 0);
	if (data->pause == 1)
		menu_buttons(data);
	if (data->pause == 2)
		options_buttons(data);
	else if (data->pause == 3)
		texture_buttons(data);
}
