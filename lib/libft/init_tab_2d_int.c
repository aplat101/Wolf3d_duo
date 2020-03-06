/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_2d_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:09:49 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:09:50 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				**init_tab_2d_int(int line_len, int col_len)
{
	int		i;
	int		**res;

	i = 0;
	if (!(res = (int**)malloc(sizeof(int*) * line_len)))
		return (NULL);
	while (i < line_len)
	{
		if (!(res[i] = (int*)malloc(sizeof(int) * col_len)))
			return (NULL);
		i++;
	}
	return (res);
}
