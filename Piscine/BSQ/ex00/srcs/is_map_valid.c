/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:18:10 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 22:21:33 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

int	is_char_valid(t_data *data)
{
	int				i;
	unsigned int	nbrlines;

	i = 0;
	nbrlines = 0;
	while (data->map[i] != '\n')
		i++;
	while (data->map[i] != '\0')
	{
		if (data->map[i] != data->empty && data->map[i] != data->obstacle
			&& data->map[i] != data->filler && data->map[i] != '\n')
		{
			return (0);
		}
		if (data->map[i] == '\n')
			nbrlines++;
		i++;
	}
	if (data->nb_lines != nbrlines)
		return (0);
	return (1);
}

int	len_lines_validation(t_data *data, int i, int linelen)
{
	int	j;

	j = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == '\n')
		{
			if (linelen != j)
				return (0);
			j = 0;
		}
		else
			j++;
		i++;
	}
	return (1);
}

int	len_lines_is_valid(t_data *data)
{
	int	i;
	int	j;
	int	linelen;

	linelen = 0;
	i = 0;
	j = 0;
	while (data->map[i - 1] != '\n')
		i++;
	while (data->map[i + j] != '\n' && data->map[i + j] != '\0')
		j++;
	linelen = j;
	i += j + 1;
	if (len_lines_validation(data, i, linelen))
	{
		data->len_lines = linelen;
		return (1);
	}
	return (0);
}

int	map_arg(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != '\n' && data->map[i] != '\0')
		i++;
	if (data->map[i] == '\0')
		return (0);
	if (i < 4)
		return (0);
	i -= 3;
	data->nb_lines = ft_atoi(data->map, i);
	if (data->nb_lines == 0)
		return (0);
	while (data->map[i] != '\n')
		if (data->map[i++] < 32 || data->map[i] > 126)
			return (0);
	if (data->map[i - 1] == data->map[i - 2]
		|| data->map[i - 1] == data->map[i - 3]
		|| data->map[i - 2] == data->map[i - 3])
		return (0);
	data->empty = data->map[i - 3];
	data->obstacle = data->map[i - 2];
	data->filler = data->map[i - 1];
	return (len_lines_is_valid(data) && is_char_valid(data));
}
