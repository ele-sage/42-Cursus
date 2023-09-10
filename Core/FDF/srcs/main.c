/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:20 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/06 10:31:03 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2 && open(av[1], O_RDONLY) != -1)
	{
		fdf = init_fdf(open(av[1], O_RDONLY));
		if (!fdf)
			return (0);
		draw(fdf);
		mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
		mlx_loop_hook(fdf->mlx, &event_handler, fdf);
		mlx_loop(fdf->mlx);
		free_fdf(fdf);
		mlx_terminate(fdf->mlx);
		free(fdf);
	}
	return (EXIT_SUCCESS);
}
