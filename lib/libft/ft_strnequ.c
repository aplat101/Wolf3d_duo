/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:03:51 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:03:52 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		res;

	if (s1 && s2)
	{
		res = ft_strncmp(s1, s2, n);
		if (res == 0)
			return (1);
	}
	return (0);
}
