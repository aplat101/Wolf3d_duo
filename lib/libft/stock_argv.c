/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:51:03 by ztrouill          #+#    #+#             */
/*   Updated: 2020/02/18 19:11:59 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*stock_param(const int fd)
{
	char		*line;
	char		*tmp;
	char		*str;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || (read(fd, NULL, 0) == -1))
		return (0);
	line = NULL;
	str = ft_strnew(1);
	while ((ret = get_next_line_feed(fd, &line)) > 0)
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	return (str);
}

char			**stock_argv(const int fd, char **tab)
{
	char		*str;

	str = stock_param(fd);
	tab = ft_strsplit(str, '\n');
	free(str);
	str = NULL;
	return (tab);
}
