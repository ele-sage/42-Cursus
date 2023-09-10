/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:18:26 by ele-sage          #+#    #+#             */
/*   Updated: 2023/03/06 10:34:48 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H

# define COLOR_H

# include "fdf.h"

# define COLOR_SUNFLOWER 0xF7D23DFF
# define COLOR_LIME 0x9ACD32FF
# define COLOR_GREEN 0x4ABD3AFF
# define COLOR_SHAMROCK 0x2AAE49FF
# define COLOR_TURQUOISE 0x1BAF9AFF
# define COLOR_SKY_BLUE 0x1BA1E2FF
# define COLOR_BLUE 0x2D7DD2FF
# define COLOR_BLUEBERRY 0x3F51B5FF
# define COLOR_VIOLET 0x5C2E91FF
# define COLOR_LAVENDER 0x7B1FA2FF

int32_t	get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);
int32_t	ft_get_color(int x, t_point s, t_point e, float factor);
int32_t	get_default_color(int z, t_matrix *matrix);

#endif
