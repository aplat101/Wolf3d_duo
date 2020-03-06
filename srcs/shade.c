/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:21:58 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:22:00 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int			darken_color(int rgb)
{
	int r;
	int g;
	int b;
	int ret;

	r = (rgb >> 16 & 0xff) / 2;
	g = (rgb >> 8 & 0xff) / 2;
	b = (rgb & 0xff) / 2;
	ret = 0;
	ret += r << 16;
	ret += g << 8;
	ret += b;
	return (ret);
}

void		shade_area(t_data *data, int x, int y)
{
	int tmp;

	tmp = x;
	if (x < 0 || y < 0)
		return ;
	while (y < HEIGHT)
	{
		x = tmp;
		while (x < WIDTH)
		{
			data->image.image_str[y * WIDTH + x] =
			darken_color(data->image.image_str[y * WIDTH + x]);
			x++;
		}
		y++;
	}
}
