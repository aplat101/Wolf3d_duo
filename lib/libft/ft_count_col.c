/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:53:41 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 15:53:42 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_count_col(char *tab)
{
	int		col_len;

	col_len = 0;
	col_len = ft_strlen(tab);
	col_len = ft_strlen_nospace(col_len, tab);
	return (col_len);
}
