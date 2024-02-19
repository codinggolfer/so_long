/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:58:09 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/19 16:14:15 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_picture(t_game *game, int x, int y)
{
	if (game->maps[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img.wall, x * WIDHT, y * HIGHT);
	else if (game->maps[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->img.floor, x * WIDHT, y * HIGHT);
		mlx_image_to_window(game->mlx, game->img.c,
			x * WIDHT + 25, y * HIGHT + 25);
	}
	else if (game->maps[y][x] == '0' || game->maps[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->img.floor, x * WIDHT, y * HIGHT);
	else if (game->maps[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->img.e, x * WIDHT, y * HIGHT);
}

void	put_texture(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->maps[y])
	{
		x = 0;
		while (game->maps[y][x] != '\0')
		{
			add_picture(game, x, y);
			x++;
		}
		y++;
	}
	x = game->player.px;
	y = game->player.py;
	mlx_image_to_window(game->mlx, game->img.p, x * WIDHT * 1.25, y * HIGHT);
}

void	ft_init_png(t_game *game)
{
	game->img.c = mlx_texture_to_image(game->mlx,
			mlx_load_png("./../32x32 icons/taco.png"));
	mlx_resize_image(game->img.c, WIDHT * 0.5, HIGHT * 0.5);
	game->img.floor = mlx_texture_to_image(game->mlx,
			mlx_load_png("./../Free_pack/grass_1.png"));
	mlx_resize_image(game->img.floor, WIDHT, HIGHT);
	game->img.p = mlx_texture_to_image(game->mlx,
			mlx_load_png("./../manga_down.png"));
	mlx_resize_image(game->img.p, 50, HIGHT);
	game->img.e = mlx_texture_to_image(game->mlx,
			mlx_load_png("./../Free_pack/cobblestone_3.png"));
	mlx_resize_image(game->img.e, WIDHT, HIGHT);
	game->img.wall = mlx_texture_to_image(game->mlx,
			mlx_load_png("./../Free_pack/sand_1.png"));
	mlx_resize_image(game->img.wall, WIDHT, HIGHT);
	if (!game->img.p || !game->img.e || !game->img.c || !game->img.wall
		|| !game->img.floor)
		ft_error("Error: texture issue");
}