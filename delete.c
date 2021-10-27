/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:45:58 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 12:12:27 by mdesoeuv         ###   ########.fr       */
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

void	final_clean(t_tetra **tetrastruct, int tetra_nb, t_maplist *map_result)
{
	display_map(map_result->map);
	clear_maplist(&map_result);
	clear_tetrastruct(tetrastruct, tetra_nb);
	free(tetrastruct);
}
