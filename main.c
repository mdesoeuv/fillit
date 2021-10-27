/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:55:42 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/27 12:17:39 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	initialize(int *tetra_nb, char ***tetra_tab, char *filename)
{
	*tetra_nb = ft_tetracount(filename);
	*tetra_tab = ft_tetra_to_tab(filename, *tetra_nb);
}

t_tetra	**resize_all(t_tetra **tetrastruct, int tetra_nb)
{
	int	j;

	j = 0;
	while (j < tetra_nb)
		resize_tetra(tetrastruct[j++]);
	return (tetrastruct);
}

int	main(int argc, char **argv)
{
	int			tetra_nb;
	char		**tetra_tab;
	t_tetra		**tetrastruct;
	int			j;
	t_maplist	*map_result;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	initialize(&tetra_nb, &tetra_tab, argv[1]);
	if (ft_all_tetra_are_valid(tetra_tab, \
	ft_tetra_to_tab("extern_file.txt", 95)) == 0 || tetra_nb > 26)
	{
		// some free to do before exiting the prog
		ft_putendl("error");
		return (0);
	}
	tetrastruct = resize_all(tetra_to_tabstruct(tetra_tab, tetra_nb), tetra_nb);
	j = 0;
	map_result = NULL;
	while (map_result == NULL)
		map_result = placement(tetrastruct, 4 + j++, tetra_nb);
	final_clean(tetrastruct, tetra_nb, map_result);
	return (0);
}
