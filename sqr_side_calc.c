/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqr_side_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:16:50 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 11:23:21 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/* tools used to calculate rectangles coordinates */

int	height_calc(char **map, int x, int **y_max, int **y_min)
{
	int	y;
	int	size;
	int	j;

	y = 0;
	size = ft_strlen(map[0]);
	while (map[y] && map[y][x] == '.')
	{
		y++;
	}
	j = size - 1;
	if (y == j + 1)
		return (0);
	while (j >= 0 && map[j][x] == '.')
		j--;
	if (y < **y_min)
		**y_min = y;
	if (j > **y_max)
		**y_max = j;
	return (0);
}

int	max_height(char **map, int *y_max, int *y_min)
{
	int	x;
	int	size;

	x = 0;
	size = ft_strlen(map[0]);
	while (x < size)
	{
		height_calc(map, x, &y_max, &y_min);
		x++;
	}
	return (0);
}

int	width_calc(char *str, int **x_max, int **x_min)
{
	int	i;
	int	j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (str[i] == '.')
		i++;
	if (i == j + 1)
		return (-1);
	while (str[j] == '.' && j >= 0)
		j--;
	if (i < **x_min)
		**x_min = i;
	if (j > **x_max)
		**x_max = j;
	return (0);
}

int	max_width(char **map, int *x_max, int *x_min)
{
	int	y;

	y = 0;
	while (map[y])
	{
		width_calc(map[y], &x_max, &x_min);
		y++;
	}
	return (0);
}

int	sqr_side_calc(char **map, int size)
{
	int	x_max;
	int	x_min;
	int	y_max;
	int	y_min;

	x_max = 0;
	y_max = 0;
	x_min = size;
	y_min = size;
	max_width(map, &x_max, &x_min);
	max_height(map, &y_max, &y_min);
	if (x_min == size)
		return (0);
	if (x_max + 1 - x_min > y_max + 1 - y_min)
		return (x_max + 1 - x_min);
	else
		return (y_max + 1 - y_min);
}
