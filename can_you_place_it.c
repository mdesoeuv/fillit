/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_you_place_it.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:56:30 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/22 18:07:02 by mdesoeuv         ###   ########.fr       */
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

t_pos	new_pos(t_tetra *tetra, t_pos pos, int map_size)
{
	if (pos.x + 1 <= map_size - tetra->width)
		pos.x += 1;
	else if (pos.y + 1 <= map_size - tetra->height)
	{
		pos.x = 0;
		pos.y += 1;
	}
	else
	{
		pos.x = -1;
		pos.y = -1;
	}
	return (pos);
}

// t_pos	**place_em_all(char **map, t_tetra **tetratab, int tetra_nb, int i)
// {
// 	int		i;
// 	t_pos	pos;

// 	if (can_you_place_it(map, tetratab[i], pos) == 1 && i < tetra_nb)
// 	{
// 		tetratab[i]->pos = pos;
// 		place_em_all(map, tetratab, tetra_nb, i + 1);
// 	}
// 	else
// 	{
// 		place_em_all()
// 	}
	
// }