/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:48:27 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/25 16:49:16 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	draw_on_map(char **map, t_tetra tetra, int x, int y)
{
	int	i;
	int	j;
	int	x_init;

	j = 0;
	x_init = x;
	while (j < tetra.height)
	{
		i = 0;
		x = x_init;
		while (i < tetra.width)
		{
			if (tetra.graph[j][i] != '.' \
			&& (map[y][x] != '.' || map[y][x] == '\0'))
				return (0);
			if (tetra.graph[j][i] != '.')
				map[y][x] = tetra.graph[j][i];
			i++;
			x++;
		}
		j++;
		y++;
	}
	return (1);
}

char	**tetra_to_map(char **map, t_tetra *tetra)
{
	t_pos	tetra_pos;
	t_pos	map_pos;
	int		x_init;
	int		y_init;

	x_init = tetra->pos.x;
	y_init = tetra->pos.y;
	tetra_pos.y = 0;
	map_pos.y = tetra->pos.y;
	while (tetra_pos.y < tetra->height)
	{
		tetra_pos.x = 0;
		map_pos.x = x_init;
		while (tetra_pos.x < tetra->width)
		{
			map[map_pos.y][map_pos.x] = tetra->graph[tetra_pos.y][tetra_pos.x];
			(map_pos.x)++;
			(tetra_pos.x)++;
		}
		(tetra_pos.y)++;
		(map_pos.y)++;
	}
	// display_map(map);
	return (map);
}

char	**tetra_to_map_bis(char **map, t_tetra tetra)
{
	draw_on_map(map, tetra, tetra.pos.x, tetra.pos.y);
	ft_putendl("tetra_to_map bis");
	display_map(map);
	return (map);
}

char	**duplicate_map(t_maplist *map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (map->size + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < map->size)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	ft_putendl("displaying copy");
	return (map_copy);
}

t_maplist	*draw_on_list(t_maplist **map, t_tetra *tetra)
{
	t_maplist	*tmap;
	char		**map_copy;

	map_copy = duplicate_map(*map);
	tmap = new_map_elem(tetra_to_map_bis(map_copy, *tetra), (*map)->size);
	ft_putendl("adding to maplist");
	display_map(map_copy);
	maplist_add_front(map, tmap);
	return (tmap);
}

void	refresh_all_map(char **map, t_tetra **tetratab, int map_size, int tetra_nb)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_memset(map[i], '.', map_size);
		i++;
	}
	i = 0;
	while (i < tetra_nb)
	{
		tetra_to_map(map, tetratab[i]);
		i++;
	}
}
