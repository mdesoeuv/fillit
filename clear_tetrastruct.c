/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tetrastruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:24:44 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/26 17:47:14 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	clear_tetrastruct(t_tetra **struct_tab, int tetra_nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetra_nb)
	{
		j = 0;
		while (j < 4)
		{
			free(struct_tab[i]->graph[j]);
			j++;
		}
		free(struct_tab[i]->graph);
		free(struct_tab[i]);
		i++;
	}
}
