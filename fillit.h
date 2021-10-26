/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:38:30 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/26 17:10:12 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

// # include "libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_sqr_pos
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}	t_sqr_pos;

typedef struct s_tetra
{
	char	**graph;
	int		width;
	int		height;
	t_pos	pos;
	char	letter;
}	t_tetra;

typedef struct s_maplist
{
	char				**map;
	int					size;
	struct s_maplist	*next;
}	t_maplist;

int			ft_tetracount(char *filename);
char		**ft_tetra_to_tab(char *filename, int tetra_nb);
int			ft_all_tetra_are_valid(char **tetra, char **ref_tab);
t_tetra		**tetra_to_tabstruct(char **tetra_tab, int tetra_nb);
void		display_all_tetragraph(t_tetra **tetra, int tetra_nb);
void		display_map(char **map);
char		**map_int(int size);
int			sqr_side_calc(char **map, int size);
int			draw_on_map(char **map, t_tetra tetra, int x, int y);
void		delete_d_tab(char **tab, int height);
t_tetra		*resize_tetra(t_tetra *tetra);
int			max_width(char **map, int *x_max, int *x_min);
int			max_height(char **map, int *y_max, int *y_min);
void		refresh_all_map(char **map, t_tetra **tetratab, \
int map_size, int tetra_nb);
t_maplist	*new_map_elem(char **map, int size);
void		del_map_elem(t_maplist **beginlist, t_maplist *elem);
void		maplist_add_front(t_maplist **beginlist, t_maplist *elem);
void		clear_maplist(t_maplist **beginlist);
void		display_maplist(t_maplist *beginlist);
void		new_pos(t_tetra *tetra, int map_size);
int			can_you_place_it(char **map, t_tetra tetra, t_pos pos);
t_maplist	*draw_on_list(t_maplist **map, t_tetra *tetra);
int			position_recursion(t_maplist **map, t_tetra *tetra);
t_maplist	*fillit_all(t_maplist **map, t_tetra **tetra_tab, \
int current_tetra, int tetra_nb);
t_maplist	*placement(t_tetra **tetra_tab, int size, int tetra_nb);
void		clear_tetrastruct(t_tetra **struct_tab, int tetra_nb);

#endif