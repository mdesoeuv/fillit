/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_recursion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:04:53 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/25 19:35:10 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	initialize_tetra_pos(t_tetra **tetra_tab, int tetra_nb)
{
	int	i;

	i = 0;
	while (i < tetra_nb)
	{
		tetra_tab[i]->pos.x = 0;
		tetra_tab[i]->pos.y = 0;
		i++;
	}
}

t_maplist	*placement(t_tetra **tetra_tab, int size, int tetra_nb)
{
	char		**map;
	t_maplist	*tmap;

	map = map_int(size);
	tmap = new_map_elem(map, size);
	ft_putendl("---<resizing map>---");
	initialize_tetra_pos(tetra_tab, tetra_nb);
	display_map(tmap->map);
	if (fillit_all(&tmap, tetra_tab, 0, tetra_nb) != NULL)
	{
		ft_putendl("returning map");
		return (tmap);
	}
	else
		return (NULL);
}

t_maplist	*fillit_all(t_maplist **map, t_tetra **tetra_tab, int current_tetra, int tetra_nb)
{
	ft_putendl("current tetra = ");
	ft_putnbr(current_tetra);
	ft_putstr("\n");
	if (current_tetra == 0 && tetra_tab[0]->pos.x == -1 && tetra_tab[0]->pos.y == -1)
		return (NULL);
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
		return(fillit_all(map, tetra_tab, current_tetra + 1, tetra_nb));
	}
	else
	{
		ft_putendl("backtracking");
		del_map_elem(map, *map);
		tetra_tab[current_tetra]->pos.x = 0;
		tetra_tab[current_tetra]->pos.y = 0;
		new_pos(tetra_tab[current_tetra - 1], (*map)->size);
		return(fillit_all(map, tetra_tab, current_tetra - 1, tetra_nb));
	}
}
