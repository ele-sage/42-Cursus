/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:17:53 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 22:23:28 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

int	skip_map_args(t_data data)
{
	int	i;

	i = 0;
	while (data.map[i] != '\n')
		i++;
	return (i + 1);
}

void	print_map_solution(t_data data, t_coin coin)
{
	int	i;
	int	j;
	int	k;

	i = skip_map_args(data);
	j = 0;
	k = 0;
	while (data.map[i] != '\0')
	{
		if (j >= coin.corner[0] && j <= coin.corner[0] + coin.len - 1
			&& k >= coin.corner[1] && k <= coin.corner[1] + coin.len - 1)
			ft_putchar(data.filler);
		else
			ft_putchar(data.map[i]);
		if (data.map[i] == '\n')
		{
			j = 0;
			k++;
		}
		else if (data.map[i] != '\n')
			j++;
		i++;
	}
}

void	print_map(t_data data)
{
	int	i;

	i = 0;
	while (data.map[i] != '\0')
	{
		ft_putchar(data.map[i]);
		i++;
	}
	write(1, "\n\n", 2);
}
