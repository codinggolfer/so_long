/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:10:42 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/21 14:31:12 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_calls(mlx_key_data_t keycode, void *param)
{
	t_game		*game;

	game = param;
	if (keycode.key == MLX_KEY_ESCAPE)
		ft_error ("Quit Game ESC clicked");
	else if (keycode.key == MLX_KEY_W && keycode.action == MLX_RELEASE)
		move_up(game);
	else if (keycode.key == MLX_KEY_S && keycode.action == MLX_RELEASE)
		move_down(game);
	else if (keycode.key == MLX_KEY_A && keycode.action == MLX_RELEASE)
		move_left(game);
	else if (keycode.key == MLX_KEY_D && keycode.action == MLX_RELEASE)
		move_right(game);
}

void	ft_init_game(t_game game)
{
	game.moves = 1;
	game.mlx = mlx_init(WIDHT * game.x, HIGHT * game.y, "Stone", true);
	if (!game.mlx)
		ft_error("Error game init");
	ft_init_png(&game);
	put_texture(&game);
	mlx_key_hook(game.mlx, &key_calls, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
