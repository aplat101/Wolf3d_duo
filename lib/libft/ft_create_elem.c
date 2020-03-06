/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:52:13 by widrye            #+#    #+#             */
/*   Updated: 2020/02/18 17:52:30 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(char *line)
{
	t_list *list;

	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = line;
	list->next = NULL;
	return (list);
}
