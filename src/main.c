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

#include "cub3d.h"

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

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 2)
		die("Usage: ./cub3d [.cub file]");
	init_rules(&rules);
	init_window(&rules.mlx);
	read_file(argv[1], &rules);
	add_events(&rules);
	mlx_loop_hook(rules.mlx.mlx, loop_events, &rules);
	mlx_loop(rules.mlx.mlx);
	return (0);
}
