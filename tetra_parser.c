/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:41:57 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/29 14:45:00 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*ft_tetra_to_str(char *buffer)
{
	int		i;
	char	*tetra_str;

	tetra_str = (char *)ft_calloc(22, 1);
	if (!tetra_str)
		return (NULL);
	i = 0;
	while (i < 20)
	{
		tetra_str[i] = buffer[i];
		i++;
	}
	tetra_str[i] = 0;
	return (tetra_str);
}

char	**ft_tetra_to_tab(char *filename, int tetra_nb)
{
	char	**tetra_tab;
	int		i;
	int		fd;
	char	*buffer;

	tetra_tab = (char **)malloc(sizeof(char *) * (tetra_nb + 1));
	if (!tetra_nb)
		exit(EXIT_FAILURE);
	buffer = calloc(22, 1);
	if (!buffer)
		exit(EXIT_FAILURE);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (read(fd, buffer, 21))
	{
		tetra_tab[i] = ft_tetra_to_str(buffer);
		ft_memset(buffer, 0, 22);
		i++;
	}
	tetra_tab[i] = 0;
	close(fd);
	free(buffer);
	return (tetra_tab);
}

t_tetra	*ft_new_elem(void)
{
	t_tetra	*new_elem;
	int		i;

	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
		exit(EXIT_FAILURE);
	new_elem->graph = ft_calloc(sizeof(char *), 5);
	if (!new_elem->graph)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < 4)
	{
		new_elem->graph[i] = calloc(sizeof(char), 5);
		if (!(new_elem->graph[i]))
			exit(EXIT_FAILURE);
		i++;
	}
	return (new_elem);
}

t_tetra	*tetra_struct(char *tetra, int pos)
{
	t_tetra	*tetra_struct;
	int		i;
	int		x;
	int		y;

	tetra_struct = ft_new_elem();
	i = 0;
	x = 0;
	y = 0;
	while (tetra[i])
	{
		if (tetra[i] == '.')
			tetra_struct->graph[y][x++] = tetra[i];
		else
			tetra_struct->graph[y][x++] = 'A' + pos;
		if (tetra[++i] == '\n')
		{
			tetra_struct->graph[y++][x] = 0;
			x = 0;
			i++;
		}
	}
	tetra_struct->graph[y] = NULL;
	tetra_struct->letter = 'A' + pos;
	return (tetra_struct);
}

t_tetra	**tetra_to_tabstruct(char **tetra_tab, int tetra_nb)
{
	int		i;
	t_tetra	**struct_tab;

	struct_tab = malloc(sizeof(*struct_tab) * tetra_nb);
	if (!struct_tab)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < tetra_nb)
	{
		struct_tab[i] = tetra_struct(tetra_tab[i], i);
		i++;
	}
	delete_d_tab(tetra_tab, tetra_nb);
	return (struct_tab);
}
