/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:57:43 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/21 14:16:29 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

void	free_all(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != '\0')
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

int	main(int ac, char **av)
{
	static t_game	map;

	if (ft_strlen(av[1]) <= 4)
		ft_error("Error: not a propper map file");
	ft_init_map(&map, ac, av[1]);
	ft_init_game(map);
	free_all(map.maps);
	free_all(map.map_cpy);
	exit (0);
}
