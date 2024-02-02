/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/02 14:41:36 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# ifndef WIDHT
#  define WIDHT 256
# endif

# ifndef HIGHT
#  define HIGHT 256
# endif


typedef struct so_long
{
	void		*window;
	void		*content;
	int32_t		hight;
	int32_t		widht;
}	t_mlx;



#endif