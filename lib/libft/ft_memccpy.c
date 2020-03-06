/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:57:14 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 15:57:15 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*s1;
	const char			*s2;
	size_t				i;

	s1 = (char*)dest;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
		{
			s1[i] = s2[i];
			return (&dest[i + 1]);
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
