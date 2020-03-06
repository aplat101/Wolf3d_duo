/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:58:03 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 15:58:04 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t n)
{
	size_t		i;
	char		*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		s[i] = (char)c;
		i++;
	}
	return (s);
}
