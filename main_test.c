// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_test.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/10/19 11:13:17 by mdesoeuv          #+#    #+#             */
// /*   Updated: 2021/10/22 18:15:07 by mdesoeuv         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"
// #include "fillit.h"

// int	main(int argc, char **argv)
// {
// 	char	**tetra_tab;
// 	char	**tetra_tab_ref;
// 	int		tetra_nb;
// 	t_tetra	**tetrastruct;
// 	int		i;
// 	char	**map;
// 	int		sqr_side;

// 	if (argc < 2)
// 		return (0);
// 	tetra_nb = ft_tetracount(argv[1]);
// 	printf("tetra count = %d\n", tetra_nb);
// 	tetra_tab = ft_tetra_to_tab(argv[1], tetra_nb);
// 	tetra_tab_ref = ft_tetra_to_tab("tetraminos_list", 89);
// 	if (ft_all_tetra_are_valid(tetra_tab, tetra_tab_ref) == 0)
// 	{
// 		ft_putendl("error");
// 		return (0);
// 	}
// 	else
// 		ft_putendl("all tetras are valid\n");
// 	i = 0;
// 	tetrastruct = tetra_to_tabstruct(tetra_tab, tetra_nb);
// 	while (i < tetra_nb)
// 	{
// 		resize_tetra(tetrastruct[i]);
// 		i++;
// 	}
// 	tetrastruct[0]->pos.x = 2;
// 	tetrastruct[0]->pos.y = 1;
// 	display_all_tetragraph(tetrastruct, tetra_nb);
// 	// map = map_int(4 + tetra_nb - 1);
// 	map = map_int(5);
// 	map[0][3] = 'Z';
// 	refresh_all_map(map, tetrastruct, 4 + tetra_nb - 1, tetra_nb);
// 	// if (draw_on_map(map, tetrastruct[0], 0, 0) == 0)
// 	// 	ft_putendl("impossible to draw this tetra");
// 	// if (draw_on_map(map, tetrastruct[1], 0, 1) == 0)
// 	// 	ft_putendl("impossible to draw this tetra");
// 	// if (draw_on_map(map, tetrastruct[2], 3, 1) == 0)
// 	// 	ft_putendl("impossible to draw this tetra");
// 	display_map(map);
// 	sqr_side = sqr_side_calc(map, 4 + tetra_nb - 1);
// 	ft_putstr("max surface = ");
// 	ft_putnbr(sqr_side);
// 	ft_putstr("\n");
// 	return (0);
// }
