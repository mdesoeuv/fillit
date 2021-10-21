/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:38:30 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/21 10:22:43 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

// # include "libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_tetra
{
	char	**graph;
	char	letter;
}	t_tetra;

int		ft_tetracount(char *filename);
char	**ft_tetra_to_tab(char *filename, int tetra_nb);
int		ft_all_tetra_are_valid(char **tetra, char **ref_tab);
t_tetra	**tetra_to_tabstruct(char **tetra_tab, int tetra_nb);
void	display_all_tetragraph(t_tetra **tetra, int tetra_nb);
void	display_map(char **map);
char	**map_int(int size);
int		sqr_side_calc(char **map);

#endif