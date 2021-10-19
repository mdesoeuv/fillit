/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:41:57 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/19 15:59:10 by mdesoeuv         ###   ########.fr       */
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
		return (NULL);
	buffer = calloc(22, 1);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, 21))
	{
		tetra_tab[i] = ft_tetra_to_str(buffer);
		ft_memset(buffer, 0, 22);
		i++;
	}
	tetra_tab[i] = 0;
	return (tetra_tab);
}
