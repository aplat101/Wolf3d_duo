/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:04:04 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:04:04 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char*)&s1[i]);
	while (i < n)
	{
		while (s1[i + j] == s2[j] && (i + j) < n && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char*)&s1[i]);
		else if (s1[i] == '\0')
			return (NULL);
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
