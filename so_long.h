/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/19 16:34:51 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef WIDHT
#  define WIDHT 75
# endif

# ifndef HIGHT
#  define HIGHT 75
# endif

typedef struct s_position
{
	int	px;
	int	py;
}	t_position;

typedef struct s_png
{
	mlx_image_t	*p;
	mlx_image_t	*c;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*e;
}	t_png;

typedef struct s_game
{
	t_png			img;
	int				y;
	int				x;
	t_position		player;
	int				temp_col;
	int				collect;
	int				exit;
	char			**maps;
	char			**map_cpy;
	void			*mlx;
	int				moves;
}	t_game;

void	ft_error(char *msg);
void	check_map(int fd, t_game *map);
void	path_check(t_game *map);
void	ft_init_map(t_game *map, int ac, char *argv);
void	ft_init_game(t_game map);
void	key_calls(mlx_key_data_t keycode, void *param);
void	add_picture(t_game *game, int x, int y);
void	put_texture(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	remove_coin(t_game *game);
void	ft_init_png(t_game *game);

#endif