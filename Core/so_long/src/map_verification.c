/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_verification->c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student->42->fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:50:29 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/18 17:39:09 by ele-sage         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_sides_valid(t_data *data, int width)
{
	int	maplen;
	int	i;

	i = 0;
	maplen = ft_strlen(data->map);
	while (data->map[i])
	{
		if (i < width || i > maplen - width)
		{
			if (data->map[i] != '1')
				return (0);
		}
		else if (data->map[i] == '\n')
		{
			if (data->map[i - 1] != '1' || data->map[i + 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_data *data)
{
	int	tab[3];
	int	i;

	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'P')
			tab[0]++;
		else if (data->map[i] == 'E')
			tab[1]++;
		else if (data->map[i] == 'C')
			tab[2]++;
		else if (data->map[i] != '1' && data->map[i] != '0'
				&& data->map[i] != '\n')
			return (0);
		i++;
	}
	if (tab[0] != 1 || tab[1] != 1 || tab[2] == 0)
		return (0);
	return (1);
}

int	is_lines_len_valid(t_data *data)
{
	int	line_len;
	int	nb_lines;
	int	last_len;
	int	i;

	i = 0;
	line_len = 0;
	nb_lines = 0;
	last_len = 0;
	while (data->map[i])
	{
		if (data->map[i] == '\n')
		{
			nb_lines++;
			if (last_len == 0)
				last_len = line_len;
			if (last_len == line_len)
				line_len = 0;
			else
				return (0);
		}
		else
			line_len++;
		i++;
	}
	data->width = last_len;
	data->height = nb_lines + 1;
	return ((last_len == line_len) && is_sides_valid(data, last_len));
}

int	map_arg(t_data *data)
{
	return (is_map_valid(data) && is_lines_len_valid(data));
}