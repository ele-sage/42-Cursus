/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:50:29 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/18 19:42:14 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_big_map(t_data *data, int fd, size_t buffer_size, size_t size)
{
	char	*buffer;
	ssize_t	ret;

	buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
	if (!buffer)
		return (0);
	ret = read(fd, buffer, buffer_size);
	buffer[ret] = '\0';
	while (ret != 0 && ret != EOF)
	{
		data->map = ft_strjoin_mod(data->map, size, buffer, buffer_size);
		if (!data->map)
			return (0);
		size += ret;
		ret = read(fd, buffer, buffer_size);
		buffer[ret] = '\0';
	}
	free(buffer);
	return (1);
}

int	read_map(t_data *data, int fd, size_t buffer_size)
{
	ssize_t	ret;

	data->map = (char *)malloc(sizeof(char) * BUFFER_INIT + 1);
	if (!data->map)
		return (0);
	ret = read(fd, data->map, BUFFER_INIT);
	data->map[ret] = '\0';
	if (ret != 0 && ret != EOF)
		if (!read_big_map(data, fd, buffer_size, ret))
			return (0);
	return (1);
}

int	read_file(t_data *data, char *file)
{
	data->map = NULL;
	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return (0);
	if (!read_map(data, data->fd, BUFFER_SIZE))
	{
		close(data->fd);
		return (0);
	}
	close(data->fd);
	return (map_arg(data));
}
