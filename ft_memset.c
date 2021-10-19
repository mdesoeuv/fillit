/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:17:46 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/18 10:56:30 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	char			*adress;

	if (b == NULL)
		return (NULL);
	ch = c;
	i = 0;
	adress = (char *)b;
	while (i < len)
	{
		adress[i] = ch;
		i++;
	}
	return (b);
}
