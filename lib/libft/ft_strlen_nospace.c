/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_nospace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:03:07 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:03:08 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlen_nospace(int col_len, char *tab)
{
	int		i;
	int		end;

	end = col_len;
	i = 0;
	while (i <= end)
	{
		while (tab[i] == ' ' && tab[i] != '\0')
		{
			i++;
			col_len--;
		}
		i++;
	}
	return (col_len);
}
