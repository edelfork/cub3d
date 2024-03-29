/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:31:44 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	choose_x(t_draw_info *info, float ref, t_rules *rules)
{
	return (our_modulo(ref, rules->map.block_width) * info->tex->width
		/ rules->map.block_width);
}

int	choose_y(int var, t_draw_info *info)
{
	return ((var - info->off) * info->tex->width / info->l_h);
}

t_image	*choose_supp(t_rules *rules, t_bres_data *d)
{
	if (!our_modulo(d->xy2[1], rules->map.block_width)
		&& d->ray_angle <= M_PI && d->ray_angle >= 0)
	{
		if (is_door((int)(d->xy2[0] / rules->map.block_width),
			(int)(d->xy2[1] / rules->map.block_width) - 1, rules))
			return (rules->door);
		return (rules->south);
	}
	else if (!our_modulo(d->xy2[1], rules->map.block_width)
		&& d->ray_angle > M_PI && d->ray_angle <= 2 * M_PI)
	{
		if (is_door((int)(d->xy2[0] / rules->map.block_width),
			(int)(d->xy2[1] / rules->map.block_width), rules))
			return (rules->door);
		return (rules->north);
	}
	else
		die("Error while choosing textures. Developers fault. Aborting");
	return (NULL);
}

t_image	*choose_texture(t_rules *rules, t_bres_data *d)
{
	if (!our_modulo(d->xy2[0], rules->map.block_width)
		&& (d->ray_angle < M_PI / 2 || d->ray_angle > 3 * M_PI / 2))
	{
		if (is_door((int)(d->xy2[0] / rules->map.block_width), (int)(d->xy2[1]
			/ rules->map.block_width), rules))
			return (rules->door);
		return (rules->east);
	}
	else if (!our_modulo(d->xy2[0], rules->map.block_width)
		&& d->ray_angle >= M_PI / 2 && d->ray_angle <= 3 * M_PI / 2)
	{
		if (is_door((int)(d->xy2[0] / rules->map.block_width) - 1,
			(int)(d->xy2[1] / rules->map.block_width), rules))
			return (rules->door);
		return (rules->west);
	}
	else
		return (choose_supp(rules, d));
}
