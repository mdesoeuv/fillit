/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tetrastruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:39:31 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/20 15:26:21 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	display_tetragraph(t_tetra *tetra)
{
	int	y;

	y = 0;
	while (tetra->graph[y] != NULL)
	{
		ft_putendl(tetra->graph[y]);
		y++;
	}
	ft_putendl("\n");
}

void	display_all_tetragraph(t_tetra **tetra_tab_struct, int tetra_nb)
{
	int	i;

	i = 0;
	while (i < tetra_nb)
	{
		ft_putstr("Tetra = ");
		ft_putchar(tetra_tab_struct[i]->letter);
		ft_putendl("\n");
		display_tetragraph(tetra_tab_struct[i]);
		i++;
	}
}