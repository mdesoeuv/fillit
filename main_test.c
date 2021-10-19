/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:13:17 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/19 11:18:26 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("tetra count = %d\n", ft_tetracount(argv[1]));
	return (0);
}
