/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:36:40 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/19 16:41:56 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_coin(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	y = 0;
	while (game->maps[game->player.py][game->player.px] == 'C')
	{
		x = 0;
		while (game->maps[y][x] != '\0')
		{
			if (game->maps[y][x] == 'C')
				i++;
			if (x == game->player.px && y == game->player.py)
			{
				game->img.c->instances[i].enabled = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_up(t_game *game)
{
	if (game->maps[game->player.py - 1][game->player.px] == '1')
		return ;
	game->player.py--;
	if (game->maps[game->player.py][game->player.px] == 'C')
	{
		remove_coin(game);
		game->collect--;
	}
	game->img.p->instances->y -= WIDHT;
	ft_printf("%d\n", game->moves++);
}

void	move_down(t_game *game)
{
	if (game->maps[game->player.py + 1][game->player.px] == '1')
		return ;
	game->player.py++;
	if (game->maps[game->player.py][game->player.px] == 'C')
	{
		remove_coin(game);
		game->collect--;
	}
	game->img.p->instances->y += WIDHT;
	ft_printf("%d\n", game->moves++);
}

void	move_left(t_game *game)
{
	if (game->maps[game->player.py][game->player.px - 1] == '1')
		return ;
	game->player.px--;
	if (game->maps[game->player.py][game->player.px] == 'C')
	{
		remove_coin(game);
		game->collect--;
	}
	game->img.p->instances->x -= HIGHT;
	ft_printf("%d\n", game->moves++);
}

void	move_right(t_game *game)
{
	if (game->maps[game->player.py][game->player.px + 1] == '1')
		return ;
	game->player.px++;
	if (game->maps[game->player.py][game->player.px] == 'C')
	{
		remove_coin(game);
		game->collect--;
	}
	game->img.p->instances->x += HIGHT;
	ft_printf("%d\n", game->moves++);
	
}
