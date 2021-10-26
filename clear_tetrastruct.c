/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tetrastruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:24:44 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/26 16:53:57 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	clear_tetrastruct(t_tetra **struct_tab, int tetra_nb)
{
	int	i;

	i = 0;
	while (i < tetra_nb)
	{
		delete_d_tab((struct_tab[i])->graph);
		free(struct_tab[i]);
		i++;
	}
}
