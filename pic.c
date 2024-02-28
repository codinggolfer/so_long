/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:58:09 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/28 11:29:34 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_picture(t_game *g, int x, int y)
{
	if (mlx_image_to_window(g->mlx, g->img.floor, x * WIDHT, y * HIGHT) == -1)
		ft_error("Error: flooring images");
	if (g->maps[y][x] == '1')
	{
		if (mlx_image_to_window(g->mlx, g->img.wall,
				x * WIDHT, y * HIGHT) == -1)
			ft_error("Error: wall pictures");
	}
	else if (g->maps[y][x] == 'C')
	{
		if (mlx_image_to_window(g->mlx, g->img.c,
				x * WIDHT + 25, y * HIGHT + 25) == -1)
			ft_error("Error: collect image");
	}
	else if (g->maps[y][x] == 'E')
	{
		g->y = y;
		g->x = x;
	}
}

void	put_texture(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->maps[y])
	{
		x = 0;
		while (g->maps[y][x] != '\0')
		{
			add_picture(g, x, y);
			x++;
		}
		y++;
	}
	x = g->player.px;
	y = g->player.py;
	if (mlx_image_to_window(g->mlx, g->img.p, x * WIDHT, y * HIGHT) < 0)
		ft_error("Error: player image");
}

void	ft_init_png(t_game *g)
{
	static mlx_texture_t	*temp;
	static mlx_texture_t	*temp2;
	static mlx_texture_t	*temp3;
	static mlx_texture_t	*temp4;
	static mlx_texture_t	*temp5;

	temp = mlx_load_png("./textures/kuponki.png");
	g->img.c = mlx_texture_to_image(g->mlx, temp);
	mlx_resize_image(g->img.c, WIDHT * 0.5, HIGHT * 0.5);
	temp2 = mlx_load_png("./textures/cobblestone_2.png");
	g->img.floor = mlx_texture_to_image(g->mlx, temp2);
	mlx_resize_image(g->img.floor, WIDHT, HIGHT);
	temp3 = mlx_load_png("./textures/sensei.png");
	g->img.p = mlx_texture_to_image(g->mlx, temp3);
	mlx_resize_image(g->img.p, 50, HIGHT);
	temp4 = mlx_load_png("./textures/shop.png");
	g->img.e = mlx_texture_to_image(g->mlx, temp4);
	mlx_resize_image(g->img.e, WIDHT, HIGHT);
	temp5 = mlx_load_png("./textures/building2.png");
	g->img.wall = mlx_texture_to_image(g->mlx, temp5);
	mlx_resize_image(g->img.wall, WIDHT, HIGHT);
	if (!g->img.p || !g->img.e || !g->img.c || !g->img.wall
		|| !g->img.floor)
		ft_error("Error: texture issue");
}
