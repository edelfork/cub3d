/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:59:10 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_pov_supp(t_rules *rules)
{
	if (rules->player.dir == (double)M_PI)
		rules->player.d_y = 0;
	else
		rules->player.d_y = -sin(rules->player.dir);
	if (rules->keys.shift_pressed)
		rules->player.speed = SPEED * 2;
	else
		rules->player.speed = SPEED;
	if (rules->keys.e_pressed)
		interact_with_door(rules);
	reload_sprites(rules);
	restore_gun(rules);
	rules->player.gun.counted = 0;
}

void	update_pov(t_rules *rules)
{
	if (rules->keys.w_pressed)
		move_player(rules, "up");
	if (rules->keys.a_pressed)
		move_player(rules, "left");
	if (rules->keys.s_pressed)
		move_player(rules, "down");
	if (rules->keys.d_pressed)
		move_player(rules, "right");
	if (rules->keys.l_pressed)
	{
		rules->player.dir = increment_angle(rules->player.dir, 40);
		rules->player.plane = increment_angle(rules->player.plane, 40);
	}
	if (rules->keys.r_pressed)
	{
		rules->player.dir = decrement_angle(rules->player.dir, 40);
		rules->player.plane = decrement_angle(rules->player.plane, 40);
	}
	rules->player.d_x = cos(rules->player.dir);
	update_pov_supp(rules);
	rules->player.plane_x = -cos(rules->player.plane);
	rules->player.plane_y = sin(rules->player.plane);
}

int	loop_events(t_rules *rules)
{
	if (!(rules->n_frames % 170))
	{
		if (rules->game_status == PLAY)
			update_pov(rules);
		decide_game(rules);
		if (rules->game_status == PLAY)
		{
			if (rules->keys.shift_pressed)
				move_gun(&rules->player.gun, 5);
			else
				move_gun(&rules->player.gun, 10);
		}
		rules->n_frames++;
	}
	else
		rules->n_frames++;
	return (0);
}
