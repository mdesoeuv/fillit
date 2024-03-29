/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesoeuv <mdesoeuv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:19:25 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/10/15 17:24:14 by mdesoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	i = 0;
	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	while (un_s1[i])
	{
		if (un_s1[i] - un_s2[i] != 0)
			return (un_s1[i] - un_s2[i]);
		i++;
	}
	return (un_s1[i] - un_s2[i]);
}
