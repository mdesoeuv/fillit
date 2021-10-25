/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_recursion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:55:42 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/25 18:24:35 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int			tetra_nb;
	char		**tetra_tab;
	char		**tetra_tab_ref;
	t_tetra		**tetrastruct;
	int			i;
	int			j;
	t_maplist 	*map_result;

	if (argc < 2)
		return (0);
	tetra_nb = ft_tetracount(argv[1]);
	printf("tetra count = %d\n", tetra_nb);
	tetra_tab = ft_tetra_to_tab(argv[1], tetra_nb);
	tetra_tab_ref = ft_tetra_to_tab("tetraminos_list", 89);
	if (ft_all_tetra_are_valid(tetra_tab, tetra_tab_ref) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	else
		ft_putendl("all tetras are valid\n");
	i = 0;
	tetrastruct = tetra_to_tabstruct(tetra_tab, tetra_nb);
	display_all_tetragraph(tetrastruct, tetra_nb);
	while (i < tetra_nb)
	{
		resize_tetra(tetrastruct[i]);
		i++;
	}
	ft_putendl("resized =");
	display_all_tetragraph(tetrastruct, tetra_nb);
	j = 0;
	map_result = NULL;
	while (map_result == NULL && j < 3)
	{
		map_result = placement(tetrastruct, 4 + j, tetra_nb);
		j++;
	}
	display_map(map_result->map);
	// all free;
	return (0);
}
