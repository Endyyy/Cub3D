/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:16:41 by alouis-j          #+#    #+#             */
/*   Updated: 2023/04/07 14:42:14 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "game_struct.h"
#include "libft.h"
#include "cub3D.h"

static void	hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		update_player_pos(&game->player, MLX_KEY_W);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		update_player_pos(&game->player, MLX_KEY_S);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_pos(&game->player, MLX_KEY_A);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_pos(&game->player, MLX_KEY_D);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(&game->player, -0.2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(&game->player, 0.2);
	calculate_rays(game);
}

void	free_map_data(t_map_data *data)
{
	free(data->west_txt);
	free(data->south_txt);
	free(data->east_txt);
	free(data->north_txt);
	ft_free_arr((void **)data->map);
}

void	ft_free_texture(t_map_data *data)
{
	free(data->north_txt);
	free(data->east_txt);
	free(data->south_txt);
	free(data->west_txt);
}

int	main(int ac, char **av)
{
	t_game	game;

	map_parsing(ac, av, &game);
	load_textures(game.textures_pxls, &game.data);
	game.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", false);
	if (!game.mlx)
	{
		free_map_data(&game.data);
		return (1);
	}
	game.img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game.img)
	{
		mlx_terminate(game.mlx);
		free_map_data(&game.data);
		return (1);
	}
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	mlx_set_cursor_mode(game.mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map_data(&game.data);
	return (0);
}
