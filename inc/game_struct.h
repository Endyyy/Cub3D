/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:01:15 by alouis-j          #+#    #+#             */
/*   Updated: 2023/03/22 14:01:17 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCT_H
# define GAME_STRUCT_H

# include "MLX42/MLX42.h"
# include "vector.h"
# include "parsing.h"
# include "constants.h"

typedef enum e_bg_color{
	CLR_TOP,
	CLR_BOT,
}	t_bg_color;

typedef enum e_txt_side{
	TXT_NORTH,
	TXT_SOUTH,
	TXT_WEST,
	TXT_EAST
}	t_txt_side;

typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
}	t_player;

typedef struct s_game
{
	t_player	player;
	t_map_data	data;
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	textures_pxls[4][TEXTURE_HEIGHT][TEXTURE_WIDTH];
	uint32_t	bg_colors[2];
}	t_game;

typedef struct s_texture_draw
{
	double		wall_x;
	double		step;
	t_vector_i	texture_coord;
	double		texture_pos;
}	t_texture_draw;

typedef struct s_raycast
{
	t_vector_d	ray_dir;
	t_vector_d	delta_dist;
	t_vector_d	side_dist;
	t_vector_i	map_pos;
	t_vector_i	step;
	double		wall_dist;
	bool		wall_hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_raycast;

#endif
