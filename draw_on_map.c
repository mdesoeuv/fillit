/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:48:27 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/22 18:15:16 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	draw_on_map(char **map, t_tetra *tetra, int x, int y)
{
	int	i;
	int	j;
	int	x_init;

	j = 0;
	x_init = x;
	while (j < tetra->height)
	{
		i = 0;
		x = x_init;
		while (i < tetra->width)
		{
			if (tetra->graph[j][i] != '.' \
			&& (map[y][x] != '.' || map[y][x] == '\0'))
				return (0);
			if (tetra->graph[j][i] != '.')
				map[y][x] = tetra->graph[j][i];
			i++;
			x++;
		}
		j++;
		y++;
	}
	return (1);
}

void	tetra_to_map(char **map, t_tetra *tetra)
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
