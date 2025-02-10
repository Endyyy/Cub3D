/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_motions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:37:02 by alouis-j          #+#    #+#             */
/*   Updated: 2023/03/25 10:35:18 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "MLX42/MLX42.h"
#include "constants_bonus.h"
#include "matrix_bonus.h"
#include "vector_bonus.h"
#include "game_struct_bonus.h"

static void	vector_rotate(t_matrix *rotation, t_vector_d *vector)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector_x * rotation->a + vector->y * rotation->b;
	vector->y = vector_x * rotation->c + vector->y * rotation->d;
}

void	rotate_player(t_player *player, double angle)
{
	t_matrix	rotation;

	rotation.a = cos(ROTATION_SPEED * angle);
	rotation.b = sin(ROTATION_SPEED * angle);
	rotation.c = -sin(ROTATION_SPEED * angle);
	rotation.d = cos(ROTATION_SPEED * angle);
	vector_rotate(&rotation, &player->dir);
	vector_rotate(&rotation, &player->plane);
}

static void	check_collisions(t_vector_d *player_pos, double new_pos_x,
		double new_pos_y, char **map)
{
	if (map[(int)new_pos_x][(int)player_pos->y] != '1')
		player_pos->x = new_pos_x;
	if (map[(int)player_pos->x][(int)new_pos_y] != '1')
		player_pos->y = new_pos_y;
}

void	update_player_pos(t_player *player, int key, char **map)
{
	if (key == MLX_KEY_W)
		check_collisions(&player->pos,
			player->pos.x + player->dir.x * PLAYER_SPEED,
			player->pos.y + player->dir.y * PLAYER_SPEED, map);
	if (key == MLX_KEY_S)
		check_collisions(&player->pos,
			player->pos.x - player->dir.x * PLAYER_SPEED,
			player->pos.y - player->dir.y * PLAYER_SPEED, map);
	if (key == MLX_KEY_A)
		check_collisions(&player->pos,
			player->pos.x - player->dir.y * PLAYER_SPEED,
			player->pos.y + player->dir.x * PLAYER_SPEED, map);
	if (key == MLX_KEY_D)
		check_collisions(&player->pos,
			player->pos.x + player->dir.y * PLAYER_SPEED,
			player->pos.y - player->dir.x * PLAYER_SPEED, map);
}

void	mouse_rotation(mlx_t *mlx, t_player *player)
{
	t_vector_i	mouse_pos;

	mlx_get_mouse_pos(mlx, &mouse_pos.x, &mouse_pos.y);
	rotate_player(player, (mouse_pos.x - SCREEN_WIDTH / 2.0) * 0.02);
	mlx_set_mouse_pos(mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
