/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:57:57 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/15 14:49:04 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_manip.h"

unsigned short	min(unsigned short **dp, unsigned short row, unsigned short col)
{
	if (dp[row + 1][col] <= dp[row][col + 1] && dp[row + 1][col] <= dp[row
		+ 1][col + 1])
	{
		return (dp[row + 1][col]);
	}
	else if (dp[row][col + 1] <= dp[row + 1][col] && dp[row][col + 1] <= dp[row
			+ 1][col + 1])
	{
		return (dp[row][col + 1]);
	}
	else
		return (dp[row + 1][col + 1]);
}

unsigned int	max(unsigned int len, unsigned short **dp, unsigned short row,
		unsigned short col)
{
	if (dp[row][col] >= len)
	{
		return (dp[row][col]);
	}
	else
		return (len);
}

unsigned short	**init_dp(unsigned short h, unsigned short w)
{
	unsigned short	**matrix;
	unsigned short	i;

	matrix = malloc(sizeof(unsigned short *) * h);
	if (!matrix)
	{
		return (NULL);
	}
	i = 0;
	while (i < h)
	{
		matrix[i] = malloc(sizeof(unsigned short) * w);
		i++;
	}
	return (matrix);
}

t_coin	find_corner(unsigned short **dp, t_data *data, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	t_coin			coin;

	coin.len = len;
	i = 0;
	while (i <= data->nb_lines - 1)
	{
		j = 0;
		while (j <= data->len_lines - 1)
		{
			printf("%d", dp[i][j]);
			if (dp[i][j] == coin.len)
			{
				coin.corner[1] = i;
				coin.corner[0] = j;
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	return (coin);
}

t_coin	find_largest_square(unsigned short **matrix, t_data *d)
{
	int				row;
	int				col;
	unsigned short	**dp;
	unsigned short	len;

	len = 0;
	row = d->nb_lines - 1;
	dp = init_dp(d->nb_lines, d->len_lines);
	while (row > -1)
	{
		col = d->len_lines - 1;
		while (col > -1)
		{
			if (matrix[row][col] == 1)
			{
				dp[row][col] = 1;
				if (row < (int)d->nb_lines - 1 && col < (int)d->len_lines - 1)
					dp[row][col] += min(dp, row, col);
				len = max(len, dp, row, col);
			}
			col--;
		}
		row--;
	}
	return (find_corner(dp, d, len));
}
