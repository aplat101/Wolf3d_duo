/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:04:44 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:04:44 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_col(char **tab, int col, int i, int height)
{
	char	tmp;
	int		line;

	line = 0;
	while (line < height)
	{
		tmp = tab[line][i];
		tab[line][i] = tab[line][col];
		tab[line][col] = tmp;
		line++;
	}
}
