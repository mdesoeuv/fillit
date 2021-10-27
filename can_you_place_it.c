/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_you_place_it.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:56:30 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 10:53:56 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	can_you_place_it(char **map, t_tetra tetra, t_pos pos)
{
	int	i;
	int	j;
	int	x_init;
	int	y_init;

	j = 0;
	x_init = pos.x;
	y_init = pos.y;
	while (j < tetra.height)
	{
		i = 0;
		pos.x = x_init;
		while (i < tetra.width)
		{
			if (tetra.graph[j][i] != '.' \
			&& (map[pos.y][pos.x] != '.' || map[pos.y][pos.x] == '\0'))
				return (0);
			i++;
			(pos.x)++;
		}
		j++;
		(pos.y)++;
	}
	return (1);
}

void	new_pos(t_tetra *tetra, int map_size)
{
	if ((tetra->pos).x + 1 <= map_size - tetra->width)
		(tetra->pos).x += 1;
	else if ((tetra->pos).y + 1 <= map_size - tetra->height)
	{
		(tetra->pos).x = 0;
		(tetra->pos).y += 1;
	}
	else
	{
		(tetra->pos).x = -1;
		(tetra->pos).y = -1;
	}
}

int	position_recursion(t_maplist **map, t_tetra *tetra)
{
	if ((tetra->pos).x == -1 && (tetra->pos).y == -1)
		return (0);
	if (can_you_place_it((*map)->map, *tetra, tetra->pos) == 1)
	{
		draw_on_list(map, tetra);
		return (1);
	}
	else
	{
		new_pos(tetra, (*map)->size);
		return (position_recursion(map, tetra));
	}
	return (1);
}
