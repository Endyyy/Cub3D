/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:12:53 by alouis-j          #+#    #+#             */
/*   Updated: 2023/04/05 13:01:30 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "game_struct_bonus.h"
#include "vector_bonus.h"
#include <math.h>

static void		init_delta_dist(t_vector_d *delta_dist, t_vector_d *ray_dir);
static void		init_loop(t_raycast *raycast, t_vector_d *player_pos);
static double	get_wall_dist(t_raycast *raycast, t_map_data *map_data);

void			draw_line(int x, t_raycast *raycast, t_game *game);

void	calculate_rays(t_game *game)
{
	int			x;
	double		camera;
	t_raycast	raycast;

	x = 0;
	while (x < game->mlx->width)
	{
		camera = 2.0 * x / game->mlx->width - 1.0;
		raycast.ray_dir.x = game->player.dir.x + game->player.plane.x * camera;
		raycast.ray_dir.y = game->player.dir.y + game->player.plane.y * camera;
		raycast.map_pos.x = (int)game->player.pos.x;
		raycast.map_pos.y = (int)game->player.pos.y;
		init_delta_dist(&raycast.delta_dist, &raycast.ray_dir);
		init_loop(&raycast, &game->player.pos);
		raycast.wall_dist = get_wall_dist(&raycast, &game->data);
		raycast.line_height = (game->mlx->height / raycast.wall_dist);
		raycast.draw_start = -raycast.line_height / 2 + game->mlx->height / 2;
		if (raycast.draw_start < 0)
			raycast.draw_start = 0;
		raycast.draw_end = raycast.line_height / 2.0 + game->mlx->height / 2.0;
		if (raycast.draw_end >= game->mlx->height)
			raycast.draw_end = game->mlx->height - 1;
		draw_line(x, &raycast, game);
		x++;
	}
}

static void	init_delta_dist(t_vector_d *delta_dist, t_vector_d *ray_dir)
{
	if (ray_dir->x == 0.0)
		delta_dist->x = INFINITY;
	else
		delta_dist->x = fabs(1.0 / ray_dir->x);
	if (ray_dir->y == 0.0)
		delta_dist->y = INFINITY;
	else
		delta_dist->y = fabs(1.0 / ray_dir->y);
}

static void	init_loop(t_raycast *raycast, t_vector_d *player_pos)
{
	if (raycast->ray_dir.x < 0.0)
	{
		raycast->step.x = -1;
		raycast->side_dist.x = (player_pos->x - raycast->map_pos.x)
			* raycast->delta_dist.x;
	}
	else
	{
		raycast->step.x = 1;
		raycast->side_dist.x = (raycast->map_pos.x + 1.0 - player_pos->x)
			* raycast->delta_dist.x;
	}
	if (raycast->ray_dir.y < 0.0)
	{
		raycast->step.y = -1;
		raycast->side_dist.y = (player_pos->y - raycast->map_pos.y)
			* raycast->delta_dist.y;
	}
	else
	{
		raycast->step.y = 1;
		raycast->side_dist.y = (raycast->map_pos.y + 1.0 - player_pos->y)
			* raycast->delta_dist.y;
	}
	raycast->wall_hit = false;
}

static double	get_wall_dist(t_raycast *raycast, t_map_data *map_data)
{
	while (!raycast->wall_hit)
	{
		if (raycast->side_dist.x < raycast->side_dist.y)
		{
			raycast->side_dist.x += raycast->delta_dist.x;
			raycast->map_pos.x += raycast->step.x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist.y += raycast->delta_dist.y;
			raycast->map_pos.y += raycast->step.y;
			raycast->side = 1;
		}
		if (raycast->map_pos.y < 0 || raycast->map_pos.x < 0
			|| raycast->map_pos.y >= map_data->map_max_x
			|| raycast->map_pos.x >= map_data->map_max_y)
			return (INFINITY);
		if (map_data->map[raycast->map_pos.x][raycast->map_pos.y] == '1')
			raycast->wall_hit = true;
	}
	if (raycast->side == 0)
		return (raycast->side_dist.x - raycast->delta_dist.x);
	else
		return (raycast->side_dist.y - raycast->delta_dist.y);
}
