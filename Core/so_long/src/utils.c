/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:27:16 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/26 15:36:43 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if(!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_strcpy_mod(char *dest, const char *src, const size_t size)
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

char	*ft_strjoin_mod(char *s1, const size_t size1, char *s2, const size_t size2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy_mod(res, s1, size1);
	ft_strcpy_mod(&res[size1], s2, size2);
	free(s1);
	return (res);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*dest;

	dest = str;
	while (n--)
		*(unsigned char *)dest++ = c;
	return (str);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nitems != 0 && SIZE_MAX / nitems < size)
		total_size = nitems * size;
	else
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}
