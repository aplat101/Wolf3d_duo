/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:17:32 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:17:35 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		init_str_textures_a(t_texture *txt)
{
	int i;

	i = 0;
	while (i < 17)
	{
		txt->wall[i].image_str = (int *)mlx_get_data_addr(txt->wall[i].
		image_ptr, &(txt->wall[i].bits_per_pixel),
		&(txt->wall[i].size_line), &(txt->wall[i].endian));
		i++;
	}
	txt->pause_box.image_str =
	(int *)mlx_get_data_addr(txt->pause_box.image_ptr, &(txt->pause_box.
	bits_per_pixel), &(txt->pause_box.size_line), &(txt->pause_box.endian));
	i = 0;
	while (i < 4)
	{
		txt->texturepacks[i].image_str = (int *)mlx_get_data_addr(txt->
		texturepacks[i].image_ptr, &(txt->texturepacks[i].bits_per_pixel),
		&(txt->texturepacks[i].size_line), &(txt->texturepacks[i].endian));
		txt->sky[i].image_str = (int *)mlx_get_data_addr(txt->sky[i].image_ptr,
		&(txt->sky[i].bits_per_pixel), &(txt->sky[i].size_line),
		&(txt->sky[i].endian));
		i++;
	}
	return (0);
}

int		init_str_textures_b(t_texture *txt)
{
	txt->end_screen[0].image_str =
	(int *)mlx_get_data_addr(txt->end_screen[0].
	image_ptr, &(txt->end_screen[0].bits_per_pixel),
	&(txt->end_screen[0].size_line), &(txt->end_screen[0].endian));
	txt->end_screen[1].image_str = (int *)mlx_get_data_addr(txt->end_screen[1].
	image_ptr, &(txt->end_screen[1].bits_per_pixel),
	&(txt->end_screen[1].size_line), &(txt->end_screen[1].endian));
	txt->pause_button.image_str = (int *)mlx_get_data_addr(txt->pause_button.
	image_ptr, &(txt->pause_button.bits_per_pixel),
	&(txt->pause_button.size_line), &(txt->pause_button.endian));
	txt->options_box.image_str = (int *)mlx_get_data_addr(txt->options_box.
	image_ptr, &(txt->options_box.bits_per_pixel),
	&(txt->options_box.size_line), &(txt->options_box.endian));
	txt->pause_arrows[0].image_str = (int *)mlx_get_data_addr(txt->
	pause_arrows[0].image_ptr, &(txt->pause_arrows[0].bits_per_pixel),
	&(txt->pause_arrows[0].size_line), &(txt->pause_arrows[0].endian));
	txt->pause_arrows[1].image_str = (int *)mlx_get_data_addr(txt->
	pause_arrows[1].image_ptr, &(txt->pause_arrows[1].bits_per_pixel),
	&(txt->pause_arrows[1].size_line), &(txt->pause_arrows[1].endian));
	return (0);
}
