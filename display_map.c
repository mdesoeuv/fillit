/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:07:37 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/21 10:13:46 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	display_map(char **map)
{
	int	y;

	ft_putendl("< map >\n");
	y = 0;
	while (map[y])
	{
		ft_putendl(map[y]);
		y++;
	}
}
