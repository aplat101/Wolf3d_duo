/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:44:54 by ztrouill          #+#    #+#             */
/*   Updated: 2020/02/18 12:52:41 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int						get_gradient_color(int range, int n, int start, int end)
{
	int				red;
	int				green;
	int				blue;
	double			percentage;

	percentage = (range) ? (double)n / (double)range : 1;
	red = get_light(((int)start >> 16) & 0xff, ((int)end >> 16)
			& 0xff, percentage);
	green = get_light(((int)start >> 8) & 0xff, ((int)end >> 8)
			& 0xff, percentage);
	blue = get_light((int)start & 0xff, (int)end
			& 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}
