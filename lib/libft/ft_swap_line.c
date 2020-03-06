/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:04:49 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:04:49 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_line(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, tmp);
	ft_strdel(&tmp);
}
