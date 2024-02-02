/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:57:43 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/02 16:08:52 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include <stdio.h>

void	check_map(int fd)
{
	char	**maps;

	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
}

int	main(void)
{
	mlx_t	*mlx;
	int		fd;

	i = 0;
	fd = open("maps.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}