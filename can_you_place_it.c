/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_you_place_it.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:56:30 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/22 16:07:48 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	can_you_place_it(char **map, t_tetra *tetra, int x, int y)
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
			// if (tetra->graph[j][i] != '.')
			// 	map[y][x] = tetra->graph[j][i];
			i++;
			x++;
		}
		j++;
		y++;
	}
	return (1);
}
