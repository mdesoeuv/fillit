/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:07:37 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 10:54:17 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	display_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_putendl(map[y]);
		y++;
	}
	ft_putstr("\n");
}

void	display_maplist(t_maplist *beginlist)
{
	while (beginlist != NULL)
	{
		display_map((beginlist)->map);
		(beginlist) = (beginlist)->next;
	}
}
