/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:11:39 by ztrouill          #+#    #+#             */
/*   Updated: 2020/02/18 15:56:21 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list			*lst;

	if (!*alst || !alst || !del)
		return ;
	lst = *alst;
	(*del)(lst->content, lst->content_size);
	ft_memdel((void**)alst);
}
