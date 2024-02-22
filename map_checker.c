/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:28:39 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/22 15:31:53 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_border(t_game *map, int i)
{
	int	j;

	j = 0;
	while (map->maps[0][j] != '\0')
	{
		if (map->maps[0][j] != map->maps[i - 1][j])
			return (0);
		if (map->maps[0][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

static void	check_req(t_game *map, int i)
{
	size_t	len;

	len = ft_strlen(map->maps[0]);
	if (!check_border(map, i))
		ft_error("Error: map is not closed or map is not reqtangular");
	while (i--)
	{
		if (ft_strlen(map->maps[i]) != len)
			ft_error("Error: map is not reqtangular");
		if (map->maps[i][0] != '1' || map->maps[i][len - 1] != '1')
			ft_error("Error: map is not closed");
		if (ft_strlen(map->maps[i]) != len)
			ft_error("Error: map is not reqtangular");
	}
}

static void	validate(t_game *map)
{
	map->y = 0;
	map->collect = 0;
	map->exit = 0;
	while (map->maps[++map->y])
	{
		map->x = 0;
		while (map->maps[map->y][map->x++])
		{
			if (!ft_strchr("01EPC", map->maps[map->y][map->x]))
				ft_error("Error: invalid map input");
			if (map->maps[map->y][map->x] == 'C')
				map->collect++;
			if (map->maps[map->y][map->x] == 'P')
			{
				map->player.px = map->x;
				map->player.py = map->y;
				map->charracter++;
			}
			if (map->maps[map->y][map->x] == 'E')
				map->exit++;
		}
	}
	if (map->exit != 1 || map->charracter != 1 || map->collect <= 0)
		ft_error("Error: invalid amount of characters found in map");
}

void	check_map(int fd, t_game *map)
{
	static char		*line;
	char			*temp;

	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		if (!line)
			line = ft_strdup(temp);
		else if (line)
			line = append_line(line, temp);
		if (!line)
			ft_error("Error: malloc failure in strdup or strjoin");
		free(temp);
	}
	if (!extra_nl(line))
		ft_error("Error: extra newlines");
	map->maps = ft_split(line, '\n');
	if (!map->maps)
		ft_error("Error: split malloc");
	map->map_cpy = ft_split(line, '\n');
}

void	ft_init_map(t_game *map, int ac, char *av)
{
	int	fd;
	int	len;

	len = ft_strlen(av) - 4;
	if (ac == 2)
	{
		fd = open(av, O_RDONLY);
		if (fd == -1 || !ft_strnstr(av + len, ".ber", 4))
		{
			ft_error("Error: invalid map");
			exit(1);
		}
		check_map(fd, map);
		close (fd);
		validate(map);
		check_req(map, map->y);
		path_check(map);
	}
	else
		ft_error("Error: no map found or too many maps");
	map->x = ft_strlen(map->maps[0]);
}
