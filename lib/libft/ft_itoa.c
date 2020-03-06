/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:55:46 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 15:55:47 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_len(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		n = -2147483647;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_res_neg(char *res, int n)
{
	res = ft_strnew(ft_nb_len(n) + 1);
	if (!res)
		return (NULL);
	res[0] = '-';
	res[ft_nb_len(n) + 1] = '\0';
	if (n == -2147483648)
		res[1] = '2';
	if (n == 0)
		res[0] = 48;
	return (res);
}

char			*ft_itoa(int n)
{
	char		*res;
	int			i;

	i = ft_nb_len(n) - 1;
	res = ft_strnew(ft_nb_len(n));
	if (!res)
		return (NULL);
	if (n > 0)
		res[ft_nb_len(n) + 1] = '\0';
	if (n <= 0)
	{
		n = -n;
		res = ft_res_neg(res, n);
		i = ft_nb_len(n);
	}
	if (n == -2147483648)
		n = 147483648;
	while (n)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (res);
}
