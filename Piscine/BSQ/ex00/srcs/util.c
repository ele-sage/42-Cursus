/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:06:52 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 22:20:51 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strcpy(char *dest, const char *src, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*ft_strjoin(char *s1, const size_t size1, char *s2, const size_t size2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1, size1);
	ft_strcpy(&res[size1], s2, size2);
	free(s1);
	return (res);
}
