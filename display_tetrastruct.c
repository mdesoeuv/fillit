/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tetrastruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:39:31 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/20 11:54:57 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	display_tetragraph(t_tetra *tetra, int tetra_nb)
{
	int	y;

	y = 0;
	while (y < tetra_nb)
	{
		ft_putendl(tetra->graph[y]);
		y++;
	}
}
