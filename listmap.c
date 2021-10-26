/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:33 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/26 17:15:32 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_maplist	*new_map_elem(char **map, int size)
{
	t_maplist	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->map = map;
	elem->size = size;
	elem->next = NULL;
	return (elem);
}

void	del_map_elem(t_maplist **beginlist, t_maplist *elem)
{
	t_maplist	*cursor;

	if (*beginlist == NULL || elem == NULL)
		return ;
	cursor = *beginlist;
	while (cursor->next != elem && cursor != *beginlist)
		cursor = cursor->next;
	cursor->next = elem->next;
	if (elem == *beginlist)
		*beginlist = elem->next;
	delete_d_tab(elem->map, elem->size);
	free(elem);
	elem = NULL;
}

void	maplist_add_front(t_maplist **beginlist, t_maplist *elem)
{
	elem->next = *beginlist;
	*beginlist = elem;
}

void	clear_maplist(t_maplist **beginlist)
{
	t_maplist	*cursor;

	cursor = *beginlist;
	while (cursor != NULL)
	{
		cursor = *beginlist;
		ft_putendl("clearing list");
		del_map_elem(beginlist, cursor);
	}
	*beginlist = NULL;
}
