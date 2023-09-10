/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:54 by ele-sage          #+#    #+#             */
/*   Updated: 2023/01/22 19:05:31 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif

# define BUFFER_INIT 4096

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

typedef struct	s_img
{
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
}				t_img;

typedef struct s_imatrix
{
	int		**matrix;
	int		height;
	int		width;
}			t_imatrix;

typedef struct s_label
{
	int		*labels;
	int		n_labels;
}			t_label;

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_data
{
	char	*map;
	int		height;
	int		width;
	int		fd;
}			t_data;

typedef struct s_game
{
	char	**matrix;
	int		height;
	int		width;
	t_coord	player;
	t_coord	start;
	t_coord	exit;
	int		nb_items;
	t_coord	*items;
}			t_game;

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_game			*game;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*ground;
}				t_root;

size_t		ft_strlen(const char *str);
int			read_file(t_data *data, char *file);
int			map_arg(t_data *data);
char		*ft_strjoin_mod(char *s1, const size_t size1, char *s2,
				const size_t size2);
int		init_game(t_data *data, t_game *game);
void		*ft_calloc(size_t nitems, size_t size);
int			uf_find(int x, t_label *label);
int			uf_union(int x, int y, t_label *label);
int			uf_make_set(t_label *label);
void		uf_initialize(int max_labels, t_label *label);
void		uf_done(t_label *label);
int			valid_path(t_game *game);
t_root	*init_root(t_game *game);
void	root_destroy(t_root *root, char *errmsg, int errnum);
void	game_destroy(t_game *game);

#endif