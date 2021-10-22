/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:58:18 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/21 15:40:00 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**map_int(int size)
{
	int		x;
	int		y;
	char	**map;

	if (size == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	x = 0;
	y = 0;
	while (x < size)
	{
		map[x] = malloc(size + 1);
		if (!map[x])
			return (NULL);
		ft_memset(map[x], '.', size);
		map[x][size] = 0;
		x++;
	}
	map[size] = NULL;
	return (map);
}
