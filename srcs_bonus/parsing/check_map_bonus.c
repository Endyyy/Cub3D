/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:23 by achretie          #+#    #+#             */
/*   Updated: 2023/04/05 11:01:53 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include "libft.h"

int	ft_check_each_char_map(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i + 1])
	{
		while (map[i + 1][j + 1])
		{
			if (map[i][j] == ' ')
			{
				if ((map[i - 1][j] != '1' && map[i - 1][j] != ' ') || \
				(map[i + 1][j] != '1' && map[i + 1][j] != ' ') || \
				(map[i][j - 1] != '1' && map[i][j - 1] != ' ') || \
				(map[i][j + 1] != '1' && map[i][j + 1] != ' '))
					return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_check_map_border_bis(char *file, int max_w, int max_l, t_map_data *data)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc(sizeof(char *), (max_l + 6));
	if (!map)
		return (1);
	while (i < max_l + 5)
	{
		map[i] = ft_calloc(sizeof(char), (max_w + 5));
		if (!map[i])
			return (1);
		i++;
	}
	map = ft_add_border(max_w, max_l, map);
	map = ft_fill_middle(file, map, data);
	if (ft_check_each_char_map(map))
	{
		ft_free_arr((void **)map);
		return (1);
	}
	ft_free_arr((void **)map);
	return (0);
}

int	ft_check_map_border(char *file_data, t_map_data *data)
{
	int	i;
	int	width;
	int	length;
	int	max_width;

	i = data->map_index;
	width = 0;
	length = 0;
	max_width = 0;
	while (file_data[i])
	{
		if (file_data[i] == '\n')
		{
			if (width > max_width)
				max_width = width;
			width = 0;
			length++;
		}
		else
			width++;
		i++;
	}
	if (ft_check_map_border_bis(file_data, max_width, length, data))
		return (1);
	return (0);
}

int	ft_check_map_loop(char *file_data, int i)
{
	int	player;
	int	valid;
	int	newline;

	valid = 0;
	player = 0;
	newline = 0;
	while (file_data[i])
	{
		if (file_data[i] == 'N' || \
		file_data[i] == 'S' || file_data[i] == 'E' || \
		file_data[i] == 'W')
			player++;
		if (ft_check_valid_char(file_data, i))
			return (1);
		if (file_data[i] == '1')
			valid++;
		if (file_data[i] == '\n')
			newline++;
		i++;
	}
	if (player != 1 || valid < 8 || newline < 2)
		return (1);
	return (0);
}

int	ft_check_map(t_map_data *data, char *file_data)
{
	int	i;

	i = data->map_index;
	while (file_data[i] && file_data[i] == '\n')
		i++;
	data->map_index = i;
	if (ft_check_map_loop(file_data, i))
		return (1);
	if (ft_check_map_border(file_data, data))
		return (1);
	return (0);
}
