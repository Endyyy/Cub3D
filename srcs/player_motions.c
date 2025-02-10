/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_motions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:37:02 by alouis-j          #+#    #+#             */
/*   Updated: 2023/03/22 15:37:03 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"
#include "game_struct.h"
#include <math.h>

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

void	update_player_pos(t_player *player, int key)
{
	if (key == MLX_KEY_W)
	{
		player->pos.x += player->dir.x * PLAYER_SPEED;
		player->pos.y += player->dir.y * PLAYER_SPEED;
	}
	if (key == MLX_KEY_S)
	{
		player->pos.x -= player->dir.x * PLAYER_SPEED;
		player->pos.y -= player->dir.y * PLAYER_SPEED;
	}
	if (key == MLX_KEY_A)
	{
		player->pos.x += -player->dir.y * PLAYER_SPEED;
		player->pos.y += player->dir.x * PLAYER_SPEED;
	}
	if (key == MLX_KEY_D)
	{
		player->pos.x += player->dir.y * PLAYER_SPEED;
		player->pos.y += -player->dir.x * PLAYER_SPEED;
	}
}
