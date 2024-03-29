/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:35:18 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "engine/cub3d_engine.h"
# include "map_parser/cub3d_map.h"
# include "utils/cub3d_utils.h"
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# define _USE_MATH_DEFINES
# include <math.h>
# include <limits.h>
# define ANGLE_UNIT 0.00174
# define SPEED 3

typedef struct s_draw_coord
{
	double			start_x;
	double			end_x;
	double			start_y;
	double			end_y;
	double			width;
	double			height;
	double			bench_x;
	double			bench_y;
	unsigned int	color;
	int				t_x;
	int				t_y;
	t_image			*sprite;
}				t_draw_coord;

#endif
