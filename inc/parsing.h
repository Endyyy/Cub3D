/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:05:14 by alouis-j          #+#    #+#             */
/*   Updated: 2023/04/04 15:46:10 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_map_data
{
	char			*north_txt;
	char			*south_txt;
	char			*east_txt;
	char			*west_txt;
	unsigned char	floor_color[3];
	unsigned char	ceil_color[3];
	int				pos_player_x;
	int				pos_player_y;
	int				map_max_x;
	int				map_max_y;
	int				map_index;
	char			**map;
}	t_map_data;

typedef struct s_parse
{
	int	valid_north;
	int	valid_east;
	int	valid_south;
	int	valid_west;
	int	valid_floor;
	int	valid_ceil;
}	t_parse;

//check_start.c
int		ft_check_cub(char *av);
int		ft_check_arg(int ac, char **av);
int		ft_start(int ac, char **av, t_map_data *data, t_parse *parse);

//check_file_data.c
int		ft_check_file_data(t_map_data *data, char *file_data, t_parse *parse);
int		ft_check_map(t_map_data *data, char *file_data);

//manage_data.c
void	ft_init_data(t_map_data *data);
int		ft_manage_north(t_map_data *data, char *file_data, int i,
			t_parse *parse);
int		ft_manage_west(t_map_data *data, char *file_data, int i,
			t_parse *parse);
int		ft_manage_east(t_map_data *data, char *file_data, int i,
			t_parse *parse);
int		ft_manage_south(t_map_data *data, char *file_data, int i,
			t_parse *parse);

//main.c
void	free_map_data(t_map_data *map);

//manage_loops.c
int		ft_manage_north_loop(t_map_data *data, char *file_data, int i,
			int length);
int		ft_manage_west_loop(t_map_data *data, char *file_data, int i,
			int length);
int		ft_manage_south_loop(t_map_data *data, char *file_data, int i,
			int length);
int		ft_manage_east_loop(t_map_data *data, char *file_data, int i,
			int length);

//check_map.c
int		ft_check_map(t_map_data *data, char *file_data);

//manage_ceil_floor.c
int		ft_get_rgb_value_ceil(t_map_data *data, char *file, int i,
			t_parse *parse);
int		ft_get_rgb_value_floor(t_map_data *data, char *file, int i,
			t_parse *parse);
int		ft_manage_floor(t_map_data *data, char *file_data, int i,
			t_parse *parse);
int		ft_manage_ceiling(t_map_data *data, char *file_data, int i,
			t_parse *parse);

//fill_map.c
int		ft_check_valid_char(char *file_data, int i);
char	**ft_add_border(int max_w, int max_l, char **map);
char	**ft_fill_middle(char *file, char **map, t_map_data *data);
char	*ft_get_file(char *arg);

#endif
