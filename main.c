/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:55:42 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 11:22:26 by mdesoeuv         ###   ########.fr       */
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

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	tetra_nb = ft_tetracount(argv[1]);
	tetra_tab = ft_tetra_to_tab(argv[1], tetra_nb);
	tetra_tab_ref = ft_tetra_to_tab("extern_file.txt", 95);
	if (ft_all_tetra_are_valid(tetra_tab, tetra_tab_ref) == 0 || tetra_nb > 26)
	{
		ft_putendl("error");
		return (0);
	}
	i = 0;
	tetrastruct = tetra_to_tabstruct(tetra_tab, tetra_nb);
	delete_d_tab(tetra_tab_ref, 95);
	while (i < tetra_nb)
	{
		resize_tetra(tetrastruct[i]);
		i++;
	}
	j = 0;
	map_result = NULL;
	while (map_result == NULL)
	{
		map_result = placement(tetrastruct, 4 + j, tetra_nb);
		j++;
	}
	display_map(map_result->map);
	clear_maplist(&map_result);
	clear_tetrastruct(tetrastruct, tetra_nb);
	free(tetrastruct);
	return (0);
}