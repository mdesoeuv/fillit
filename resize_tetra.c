/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:43:19 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/22 15:50:05 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_sqr_pos	sqr_coordinates_calc(char **map, int size)
{
	t_sqr_pos	pos;

	pos.x_max = 0;
	pos.y_max = 0;
	pos.x_min = size;
	pos.y_min = size;
	max_width(map, &pos.x_max, &pos.x_min);
	max_height(map, &pos.y_max, &pos.y_min);
	return (pos);
}

char	**new_graph_init(int height, int width)
{
	char	**new_graph;
	int		i;

	new_graph = malloc(sizeof(char *) * (height + 1));
	if (!new_graph)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_graph[i] = malloc(sizeof(char) * (width + 1));
		if (!new_graph[i])
			return (NULL);
		ft_memset(new_graph[i], '.', width);
		new_graph[i][width] = 0;
		i++;
	}
	new_graph[i] = NULL;
	return (new_graph);
}

// char	**new_graph_calc()

t_tetra	*resize_tetra(t_tetra *tetra)
{
	t_sqr_pos	pos;
	t_pos		size;
	t_pos		cursor;
	char		**new_graph;

	pos = sqr_coordinates_calc(tetra->graph, 4);
	size.y = pos.y_max + 1 - pos.y_min;
	size.x = pos.x_max + 1 - pos.x_min;
	printf("width = %d\n", size.x);
	printf("height = %d\n", size.y);
	new_graph = new_graph_init(size.y, size.x);
	cursor.y = 0;
	while (pos.y_min <= pos.y_max)
	{
		ft_strncpy(new_graph[cursor.y], \
		&(tetra->graph[pos.y_min][pos.x_min]), size.x);
		(pos.y_min)++;
		(cursor.y)++;
	}
	new_graph[cursor.y] = NULL;
	free(tetra->graph);
	tetra->width = size.x;
	tetra->height = size.y;
	tetra->graph = new_graph;
	return (tetra);
}
