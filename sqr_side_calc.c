/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqr_side_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:16:50 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/21 12:02:37 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	height_calc(char **map, int x)
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
	ft_putstr("height =");
	ft_putnbr(j + 1 - y);
	ft_putstr("\n");
	return (j + 1 - y);
}

int	max_height(char **map)
{
	int	x;
	int	max;
	int	tmp;
	int	size;

	x = 0;
	max = 0;
	size = ft_strlen(map[0]);
	while (x < size)
	{
		ft_putstr("calculing height\n");
		tmp = height_calc(map, x);
		if (tmp > max)
			max = tmp;
		x++;
	}
	return (max);
}

int	width_calc(char *str)
{
	int	i;
	int	j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (str[i] == '.')
		i++;
	if (i == j + 1)
		return (0);
	while (str[j] == '.' && j >= 0)
		j--;
	ft_putstr("width =");
	ft_putnbr(j + 1 - i);
	ft_putstr("\n");
	return (j + 1 - i);
}

int	max_width(char **map)
{
	int	y;
	int	max;
	int	min;
	int	tmp;

	y = 0;
	max = 0;
	while (map[y])
	{
		ft_putstr("calculing width\n");
		tmp = width_calc(map[y]);
		if (tmp > max)
			max = tmp;
		y++;
	}
	return (max);
}

int	sqr_side_calc(char **map)
{
	int	x_max;
	int	y_max;

	x_max = max_width(map);
	y_max = max_height(map);
	if (x_max > y_max)
		return (x_max);
	else
		return (y_max);
}
