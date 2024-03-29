/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:45:37 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	mouse_exit(t_rules *rules)
{
	mlx_destroy_window(rules->mlx.mlx, rules->mlx.mlx_win);
	exit(0);
	return (0);
}

static void	move_mouse_dir(int x, int y, t_rules *rules)
{
	if (x < rules->mouse.last_x)
	{
		rules->player.dir = increment_angle(rules->player.dir,
				rules->mlx.win_width / 40);
		rules->player.plane = increment_angle(rules->player.plane,
				rules->mlx.win_width / 40);
	}
	else if (x > rules->mouse.last_x)
	{
		rules->player.dir = decrement_angle(rules->player.dir,
				rules->mlx.win_width / 40);
		rules->player.plane = decrement_angle(rules->player.plane,
				rules->mlx.win_width / 40);
	}
	rules->mouse.last_x = x;
	rules->mouse.last_y = y;
}

static int	mouse_move(int x, int y, t_rules *rules)
{
	if (x < 0 || y < 0 || x > rules->mlx.win_width || y > rules->mlx.win_height)
		return (0);
	if (!rules->mouse.moved)
	{
		rules->mouse.moved = 1;
		rules->mouse.last_x = x;
		rules->mouse.last_y = y;
	}
	move_mouse_dir(x, y, rules);
	rules->player.d_x = cos(rules->player.dir);
	if (rules->player.dir == (double)M_PI)
		rules->player.d_y = 0;
	else
		rules->player.d_y = -sin(rules->player.dir);
	rules->player.plane_x = -cos(rules->player.plane);
	rules->player.plane_y = sin(rules->player.plane);
	return (0);
}

void	add_events(t_rules *rules)
{
	mlx_hook(rules->mlx.mlx_win, 2, 1L << 0, press, rules);
	mlx_hook(rules->mlx.mlx_win, 3, 1L << 1, release, rules);
	mlx_hook(rules->mlx.mlx_win, 17, 0, mouse_exit, rules);
	mlx_hook(rules->mlx.mlx_win, 6, 1L << 6, mouse_move, rules);
}
