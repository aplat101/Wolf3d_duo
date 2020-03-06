/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:18:23 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 19:26:30 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int	init_ptr_textures_a(t_texture *txt, void *mlx_ptr)
{
	if (!(txt->wall[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/1.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[2].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/2.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/3.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[3].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/4.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[4].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/5.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[5].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/6.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[6].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/7.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[7].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/8.xpm", &(txt->size), &(txt->size))))
		return (-1);
	return (0);
}

static int	init_ptr_textures_b(t_texture *txt, void *mlx_ptr)
{
	if (!(txt->wall[8].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/9.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[9].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/10.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[10].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/11.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[11].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/12.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[12].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/13.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[13].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/14.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[14].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/15.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->wall[15].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/16.xpm", &(txt->size), &(txt->size))))
		return (-1);
	return (0);
}

static int	init_ptr_textures_c(t_texture *txt, void *mlx_ptr)
{
	if (!(txt->wall[16].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/17.xpm", &(txt->size), &(txt->size))))
		return (-1);
	if (!(txt->pause_arrows[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/arrowd.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->pause_arrows[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/arrowu.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->pause_box.image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/pause.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->pause_button.image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/button.xpm", (txt->full_width), (txt->full_height))))
		return (-1);
	if (!(txt->options_box.image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/optionsbox.xpm", (txt->full_width), (txt->full_height))))
		return (-1);
	if (!(txt->end_screen[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/fail.xpm", (txt->full_width), (txt->full_height))))
		return (-1);
	if (!(txt->end_screen[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/win.xpm", (txt->full_width), (txt->full_height))))
		return (-1);
	return (0);
}

static int	init_ptr_textures_d(t_texture *txt, void *mlx_ptr)
{
	if (!(txt->texturepacks[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/textpack1.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->texturepacks[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/textpack2.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->texturepacks[2].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/textpack3.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->texturepacks[3].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/textpack4.xpm", &(txt->icon_w), &(txt->icon_h))))
		return (-1);
	if (!(txt->sky[0].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/sky1.xpm", &(txt->full_width[0]), &(txt->full_height[0]))))
		return (-1);
	if (!(txt->sky[1].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/sky2.xpm", &(txt->full_width[1]), &(txt->full_height[1]))))
		return (-1);
	if (!(txt->sky[2].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/sky3.xpm", &(txt->full_width[2]), &(txt->full_height[2]))))
		return (-1);
	if (!(txt->sky[3].image_ptr = mlx_xpm_file_to_image(mlx_ptr,
	"textures/sky4.xpm", &(txt->full_width[3]), &(txt->full_height[3]))))
		return (-1);
	return (0);
}

int			load_xpm(t_texture *texture, void *mlx_ptr)
{
	texture->size = 256;
	texture->x = 0;
	texture->y = 0;
	texture->map_x = 0;
	texture->icon_w = WIDTH;
	texture->icon_h = HEIGHT;
	if (init_ptr_textures_a(texture, mlx_ptr) == -1)
		return (-1);
	if (init_ptr_textures_b(texture, mlx_ptr) == -1)
		return (-1);
	if (init_ptr_textures_c(texture, mlx_ptr) == -1)
		return (-1);
	if (init_ptr_textures_d(texture, mlx_ptr) == -1)
		return (-1);
	init_str_textures_a(texture);
	init_str_textures_b(texture);
	return (0);
}
