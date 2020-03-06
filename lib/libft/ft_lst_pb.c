/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 02:58:21 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 19:03:06 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pb(t_list **begin_list, char *line)
{
	t_list	*list;

	if (!begin_list || !*begin_list)
		*begin_list = ft_create_elem(line);
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		if ((list->next = ft_create_elem(line)) == NULL)
			return (NULL);
	}
	return (*begin_list);
}
