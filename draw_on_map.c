/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:48:27 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/21 16:46:05 by mdesoeuv         ###   ########.fr       */
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
	while (j < 4)
	{
		i = 0;
		x = x_init;
		while (i < 4)
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
