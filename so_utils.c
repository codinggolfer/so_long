/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:28:44 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/16 13:46:23 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	floodfill(t_game *map, int x, int y)
{
	if (map->map_cpy[y][x] == 'C' || map->map_cpy[y][x] == '0'
	|| map->map_cpy[y][x] == 'E')
	{
		if (map->map_cpy[y][x] == 'C')
			map->temp_col--;
		if (map->map_cpy[y][x] == 'E')
			map->exit--;
		map->map_cpy[y][x] = 'P';
	}
}

static int	suroundings(t_game *map, int x, int y)
{
	if (map->map_cpy[y][x] == 'P' &&
		(map->map_cpy[y - 1][x] == 'C'
		|| map->map_cpy[y + 1][x] == 'C'
		|| map->map_cpy[y][x - 1] == 'C'
		|| map->map_cpy[y][x + 1] == 'C'
		|| map->map_cpy[y - 1][x] == '0'
		|| map->map_cpy[y + 1][x] == '0'
		|| map->map_cpy[y][x - 1] == '0'
		|| map->map_cpy[y][x + 1] == '0'
		|| map->map_cpy[y - 1][x] == 'E'
		|| map->map_cpy[y + 1][x] == 'E'
		|| map->map_cpy[y][x - 1] == 'E'
		|| map->map_cpy[y][x + 1] == 'E'))
		return (1);
	return (0);
}

void	path_check(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	map->temp_col = map->collect;
	while (map->map_cpy[y])
	{
		x = 0;
		while (map->map_cpy[y][x])
		{
			if (suroundings(map, x, y))
			{
				floodfill(map, x + 1, y);
				floodfill(map, x - 1, y);
				floodfill(map, x, y + 1);
				floodfill(map, x, y - 1);
				y = 0;
			}
			x++;
		}
		y++;
	}
	if (map->exit != 0 || map->temp_col != 0)
		ft_error("Error: game cannot be finished");
}