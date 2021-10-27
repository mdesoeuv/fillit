/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:45:58 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 10:53:41 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	delete_d_tab(char **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clear_tetrastruct(t_tetra **struct_tab, int tetra_nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetra_nb)
	{
		j = 0;
		while (j < struct_tab[i]->height)
		{
			free(struct_tab[i]->graph[j]);
			j++;
		}
		free(struct_tab[i]->graph);
		free(struct_tab[i]);
		i++;
	}
}
