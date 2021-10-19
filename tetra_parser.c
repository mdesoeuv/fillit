/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:41:57 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/19 11:32:38 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	ft_check_charset(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (!(buffer[i] == '.' || buffer[i] == '#' || buffer[i] == '\n'))
			return (-1);
		i++;
	}
	printf("charset of buffer is correct\n");
	return (1);
}

int	ft_bufanalyze(char *buffer, int *count)
{
	int	i;

	i = 0;
	printf("--<checking buffer charset>--\n");
	if (ft_check_charset(buffer) == -1)
		return (-1);
	if (!(buffer[20] == '\n' || buffer[20] == '\0'))
		return (-1);
	while (buffer[i])
	{
		if ((i + 1) % 5 == 0)
		{
			if (buffer[i] != '\n')
			{
				printf ("incorrect line\n");
				return (-1);
			}
			printf ("correct line\n");
		}
		i++;
	}
	(*count)++;
	return (1);
}

int	ft_tetracount(char *filename)
{
	int		fd;
	int		count;
	char	*buffer;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	buffer = ft_calloc(22, 1);
	while (read(fd, buffer, 21))
	{
		printf("--<reading buffer>--\n");
		if (ft_bufanalyze(buffer, &count) == -1)
			return (-1);
		ft_memset(buffer, 0, 22);
	}
	return (count);
}
