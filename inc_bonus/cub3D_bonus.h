/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:30 by achretie          #+#    #+#             */
/*   Updated: 2023/03/25 10:33:26 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "constants_bonus.h"
# include "game_struct_bonus.h"
# include "parsing_bonus.h"

int		load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],
			t_map_data *data);

void	calculate_rays(t_game *game);

void	update_player_pos(t_player *player, int key, char **map);
void	rotate_player(t_player *player, double angle);
void	mouse_rotation(mlx_t *mlx, t_player *player);
void	map_parsing(int ac, char *av[], t_game *game);

#endif
