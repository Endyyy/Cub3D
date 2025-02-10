/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:30 by achretie          #+#    #+#             */
/*   Updated: 2023/04/05 11:23:53 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "constants.h"
# include "game_struct.h"
# include "parsing.h"

int		load_textures(uint32_t textures[4][TEXTURE_HEIGHT][TEXTURE_WIDTH],
			t_map_data *data);

void	calculate_rays(t_game *game);

void	update_player_pos(t_player *player, int key);
void	rotate_player(t_player *player, double angle);
void	map_parsing(int ac, char *av[], t_game *game);

#endif
