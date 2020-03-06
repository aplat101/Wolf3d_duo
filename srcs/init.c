/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:18:49 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:18:51 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		spawn(t_data *data)
{
	data->player.pos_x = floor(data->world.line_nb - 1);
	data->player.pos_y = floor(data->world.row_nb / 2);
	if (data->world.map[data->world.line_nb - 1][data->world.row_nb / 2] == 0)
		return ;
	else
	{
		while (data->world.map[(int)data->player.pos_x][(int)data->player.pos_y]
				!= 0)
		{
			if (data->player.pos_x > 0)
				data->player.pos_x--;
			else
				data->player.pos_y--;
			if (data->player.pos_y == 0)
				return ;
		}
	}
}

int				init(t_data *data, char *argv, int fd)
{
	t_image		image;

	data->map = stock_argv(fd, &argv);
	if ((check_tab(data->map) == 0))
	{
		ft_putendl(MAP);
		return (-1);
	}
	data->mlx_ptr = mlx_init();
	data->window_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
							"W 0 L F  3 D");
	image.image_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	image.image_str = (int*)mlx_get_data_addr(image.image_ptr,
			&(image.bits_per_pixel), &(image.size_line), &(image.endian));
	data->image = image;
	if (init_struct(data) == -1)
	{
		ft_putendl(TEXTURES);
		return (-1);
	}
	init_struct_values(data);
	spawn(data);
	return (0);
}
