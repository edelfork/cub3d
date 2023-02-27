/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:55:31 by gimartin          #+#    #+#             */
/*   Updated: 2023/02/27 11:34:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_MAP_H
# define CUB3D_BONUS_MAP_H

void	map_save(char *file, int fd, t_rules *rules);
void	map_checks(t_rules *rules);
void	take_rules(int fd, t_rules *rules);

#endif
