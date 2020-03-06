/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplat <aplt@student.le-101.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:22:10 by aplat             #+#    #+#             */
/*   Updated: 2020/02/18 14:22:13 by aplat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void			sky_treadmill(t_data *d, int y, int x, int offset)
{
	if (offset >= d->texture.full_width[d->texturepack])
		d->image.image_str[(y * WIDTH) + x] =
		d->texture.sky[d->texturepack].
		image_str[(y * d->texture.full_width[d->texturepack])
		+ (offset - d->texture.full_width[d->texturepack])];
	else if (offset > 0)
		d->image.image_str[(y * WIDTH) + x] =
		d->texture.sky[d->texturepack].
		image_str[(y * d->texture.full_width[d->texturepack])
		+ offset];
	else if (offset <= 0)
		d->image.image_str[(y * WIDTH) + x] =
		d->texture.sky[d->texturepack].
		image_str[(y * d->texture.full_width[d->texturepack]) - offset];
}

void				apply_sky(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT && y < d->texture.full_height[d->texturepack])
	{
		x = 0;
		while (x < WIDTH)
		{
			sky_treadmill(d, y, x, x + d->sky_offset);
			x++;
		}
	}
}
