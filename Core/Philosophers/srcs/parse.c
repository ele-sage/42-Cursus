/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:05:11 by ele-sage          #+#    #+#             */
/*   Updated: 2023/09/09 14:02:18 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	if (!str)
		return (0);
	a = 0;
	while (str[a])
		a++;
	return (a);
}

static size_t	ft_atoi_check(const char *str, int *negative)
{
	int	a;

	a = 0;
	while (str[a] && (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13)))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			*negative = -1;
		a++;
	}
	return (a);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_add_str_to_int(const char *str, int *a)
{
	long	result;

	result = 0;
	while (ft_isdigit(str[*a]))
	{
		result = result * 10 + str[*a] - '0';
		(*a)++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		negative;
	int		a;

	negative = 1;
	a = ft_atoi_check(str, &negative);
	result = ft_add_str_to_int(str, &a);
	if (result > LONG_MAX && negative == -1)
		return (0);
	else if (result > LONG_MAX && negative == 1)
		return (-1);
	return (result * negative);
}
