/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:04:31 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 16:04:32 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check_if_spaces(char const *s, size_t i, size_t s_len)
{
	if ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') ||
			(s[s_len - 1] == ' ' || s[s_len - 1] == '\n' ||
			s[s_len - 1] == '\t'))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char		*res;
	char		*cpy;
	size_t		i;
	size_t		s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	cpy = ft_strnew(s_len);
	res = ft_strnew(s_len);
	if (ft_check_if_spaces(s, i, s_len) == 1)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[s_len - 1] == ' ' || s[s_len - 1] == '\n' ||
				s[s_len - 1] == '\t')
			s_len--;
		if (s_len > 0)
			s_len = s_len - i;
		res = ft_strsub(s, i, s_len);
		return (res);
	}
	ft_strcpy(cpy, s);
	return (cpy);
}
