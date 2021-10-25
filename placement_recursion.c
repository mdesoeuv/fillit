/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_recursion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:04:53 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/25 16:45:58 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_maplist	*placement(t_tetra **tetra_tab, int size, int tetra_nb)
{
	char		**map;
	t_maplist	*tmap;

	map = map_int(size);
	tmap = new_map_elem(map, size);
	ft_putendl("---<resizing map>---");
	display_map(tmap->map);
	if (fillit_all(&tmap, tetra_tab, 0, tetra_nb) != NULL)
		return (tmap);
	else
		return (NULL);
}

t_maplist	*fillit_all(t_maplist **map, t_tetra **tetra_tab, int current_tetra, int tetra_nb)
{
	if (current_tetra == -1)
		return (NULL);
	if (current_tetra == tetra_nb)
	{
		ft_putendl("map completed");
		return (*map);
	}
	if (position_recursion(map, tetra_tab[current_tetra]) == 1)
	{
		ft_putendl("tetra placed");
		fillit_all(map, tetra_tab, current_tetra + 1, tetra_nb);
	}
	else
	{
		ft_putendl("backtracking");
		del_map_elem(map, *map);
		new_pos(tetra_tab[current_tetra - 1], (*map)->size);
		fillit_all(map, tetra_tab, current_tetra - 1, tetra_nb);
	}
	return (NULL);
}
