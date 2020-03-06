/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:42:43 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 17:43:02 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list *lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (lst)
		{
			tmp = lst;
			if (lst->content)
				free(lst->content);
			lst = lst->next;
			free(tmp);
		}
	}
}
