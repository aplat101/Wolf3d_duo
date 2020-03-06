/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:39:30 by ztrouill          #+#    #+#             */
/*   Updated: 2020/02/18 16:01:07 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_recursive_factorial(int nb)
{
	if (nb <= -1 || nb >= 13)
		return (0);
	if (nb == 0)
		return (1);
	if (nb != 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	return (nb);
}
