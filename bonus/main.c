/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:35:11 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	read_file(char *file, t_rules *rules)
{
	int	fd;

	if (ft_strncmp(&file[ft_strlen(file) - 4], ".cub", 4))
		die("Configuration file must have .cub extension");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		die("Error opening file");
	take_rules(fd, rules);
	map_save(file, fd, rules);
	close(fd);
	rules->map.block_width = (rules->mlx.win_width
			/ (rules->map.map_height_len[0] - 1));
	rules->map.mini_block_width = rules->map.block_width / 4;
	map_checks(rules);
}

void	load_animations(t_rules *rules)
{
	rules->animations = malloc(sizeof(t_image *) * 10);
	if (!rules->animations)
		die("Malloc error");
	init_xpm_img(rules, &rules->animations[0], AMMO_TEX);
	init_xpm_img(rules, &rules->animations[1], ENEMY_TEX_1);
	init_xpm_img(rules, &rules->animations[2], ENEMY_TEX_2);
	init_xpm_img(rules, &rules->animations[3], ENEMY_TEX_3);
	init_xpm_img(rules, &rules->animations[4], ENEMY_ATTK_1);
	init_xpm_img(rules, &rules->animations[5], ENEMY_ATTK_2);
	init_xpm_img(rules, &rules->animations[6], ENEMY_ATTK_3);
	init_xpm_img(rules, &rules->animations[7], ENEMY_DIE_1);
	init_xpm_img(rules, &rules->animations[8], ENEMY_DIE_2);
	init_xpm_img(rules, &rules->animations[9], ENEMY_DIE_3);
	rules->animations[10] = NULL;
}

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 2)
		die("Usage: ./cub3d [.cub file]");
	init_rules(&rules);
	init_window(&rules.mlx);
	load_gun(&rules);
	read_file(argv[1], &rules);
	load_animations(&rules);
	load_sprites(&rules);
	load_gun(&rules);
	add_events(&rules);
	mlx_loop_hook(rules.mlx.mlx, loop_events, &rules);
	mlx_loop(rules.mlx.mlx);
	return (0);
}