/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:13:17 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/19 15:37:56 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**tetra_tab;
	char	**tetra_tab_ref;
	int		tetra_nb;
	int		i;

	if (argc < 2)
		return (0);
	tetra_nb = ft_tetracount(argv[1]);
	printf("tetra count = %d\n", tetra_nb);
	tetra_tab = ft_tetra_to_tab(argv[1], tetra_nb);
	tetra_tab_ref = ft_tetra_to_tab("tetraminos_list", tetra_nb);
	i = 0;
	// while (i < tetra_nb)
	// {
	// 	printf("\nTetra %d =\n%s\n", i + 1, tetra_tab[i]);
	// 	i++;
	// }
	printf("tetra validity = %d\n", ft_all_tetra_are_valid(tetra_tab, tetra_tab_ref));
	return (0);
}
