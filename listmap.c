/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:33 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/29 14:35:01 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**map_graph_init(int size)
{
	int		x;
	int		y;
	char	**map;

	if (size == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		exit(EXIT_FAILURE);
	x = 0;
	y = 0;
	while (x < size)
	{
		map[x] = malloc(size + 1);
		if (!map[x])
			exit(EXIT_FAILURE);
		ft_memset(map[x], '.', size);
		map[x][size] = 0;
		x++;
	}
	map[size] = NULL;
	return (map);
}

t_maplist	*new_map_elem(char **map, int size)
{
	t_maplist	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		exit(EXIT_FAILURE);
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
		del_map_elem(beginlist, cursor);
	}
	*beginlist = NULL;
}
