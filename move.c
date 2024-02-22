/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:36:40 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/22 14:35:33 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_coin(t_game *g)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	y = 0;
	while (g->maps[g->player.py][g->player.px] == 'C')
	{
		x = 0;
		while (g->maps[y][x] != '\0')
		{
			if (g->maps[y][x] == 'C')
				i++;
			if (x == g->player.px && y == g->player.py)
			{
				if (g->img.c->instances[i].enabled != 0)
					g->collect--;
				g->img.c->instances[i].enabled = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_up(t_game *g)
{
	if (g->maps[g->player.py - 1][g->player.px] == '1')
		return ;
	g->player.py--;
	if (g->maps[g->player.py][g->player.px] == 'C')
		remove_coin(g);
	if (g->collect == 0 && !g->victory)
	{
		g->victory = 1;
		if (mlx_image_to_window(g->mlx, g->img.e,
				g->x * WIDHT, g->y * HIGHT) == -1)
			ft_error("Error: exit image");
	}
	g->img.p->instances->y -= WIDHT;
	ft_printf("Steps: %d\n", g->moves++);
	if (g->collect == 0
		&& g->maps[g->player.py][g->player.px] == 'E')
	{
		ft_printf("You got all the coupons and made it on time to the shop!\n");
		mlx_close_window(g->mlx);
	}
}

void	move_down(t_game *g)
{
	if (g->maps[g->player.py + 1][g->player.px] == '1')
		return ;
	g->player.py++;
	if (g->maps[g->player.py][g->player.px] == 'C')
		remove_coin(g);
	if (g->collect == 0 && !g->victory)
	{
		g->victory = 1;
		if (mlx_image_to_window(g->mlx, g->img.e,
				g->x * WIDHT, g->y * HIGHT) == -1)
			ft_error("Error: exit image");
	}
	g->img.p->instances->y += WIDHT;
	ft_printf("Steps: %d\n", g->moves++);
	if (g->collect == 0
		&& g->maps[g->player.py][g->player.px] == 'E')
	{
		ft_printf("You got all the coupons and made it on time to the shop!\n");
		mlx_close_window(g->mlx);
	}
}

void	move_left(t_game *g)
{
	if (g->maps[g->player.py][g->player.px - 1] == '1')
		return ;
	g->player.px--;
	if (g->maps[g->player.py][g->player.px] == 'C')
		remove_coin(g);
	if (g->collect == 0 && !g->victory)
	{
		g->victory = 1;
		if (mlx_image_to_window(g->mlx, g->img.e,
				g->x * WIDHT, g->y * HIGHT) == -1)
			ft_error("Error: exit image");
	}
	g->img.p->instances->x -= HIGHT;
	ft_printf("Steps: %d\n", g->moves++);
	if (g->collect == 0
		&& g->maps[g->player.py][g->player.px] == 'E')
	{
		ft_printf("You got all the coupons and made it on time to the shop!\n");
		mlx_close_window(g->mlx);
	}
}

void	move_right(t_game *g)
{
	if (g->maps[g->player.py][g->player.px + 1] == '1')
		return ;
	g->player.px++;
	if (g->maps[g->player.py][g->player.px] == 'C')
		remove_coin(g);
	if (g->collect == 0 && !g->victory)
	{
		g->victory = 1;
		if (mlx_image_to_window(g->mlx, g->img.e,
				g->x * WIDHT, g->y * HIGHT) == -1)
			ft_error("Error: exit image");
	}
	g->img.p->instances->x += HIGHT;
	ft_printf("Steps: %d\n", g->moves++);
	if (g->collect == 0
		&& g->maps[g->player.py][g->player.px] == 'E')
	{
		ft_printf("You got all the coupons and made it on time to the shop!\n");
		mlx_close_window(g->mlx);
	}
}
