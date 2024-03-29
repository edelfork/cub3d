/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:46:17 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	press(int keycode, t_rules *rules)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(rules->mlx.mlx, rules->mlx.mlx_win);
		exit(0);
	}
	if (keycode == 119)
		rules->keys.w_pressed = 1;
	if (keycode == 97)
		rules->keys.a_pressed = 1;
	if (keycode == 115)
		rules->keys.s_pressed = 1;
	if (keycode == 100)
		rules->keys.d_pressed = 1;
	if (keycode == 65361)
		rules->keys.l_pressed = 1;
	if (keycode == 65363)
		rules->keys.r_pressed = 1;
	if (keycode == 65505 || keycode == 65506)
		rules->keys.shift_pressed = 1;
	if (keycode == 101)
		rules->keys.e_pressed = 1;
	if (keycode == 32 && rules->player.ammo)
		shoot(rules);
	return (0);
}

int	release(int keycode, t_rules *rules)
{
	if (keycode == 119)
		rules->keys.w_pressed = 0;
	if (keycode == 97)
		rules->keys.a_pressed = 0;
	if (keycode == 115)
		rules->keys.s_pressed = 0;
	if (keycode == 100)
		rules->keys.d_pressed = 0;
	if (keycode == 65361)
		rules->keys.l_pressed = 0;
	if (keycode == 65363)
		rules->keys.r_pressed = 0;
	if (keycode == 65505 || keycode == 65506)
		rules->keys.shift_pressed = 0;
	if (keycode == 101)
		rules->keys.e_pressed = 0;
	return (0);
}
