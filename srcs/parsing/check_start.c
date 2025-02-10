/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:23 by achretie          #+#    #+#             */
/*   Updated: 2023/04/07 14:48:06 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parsing.h"
#include "libft.h"
#include <fcntl.h>

void	ft_free_texture(t_map_data *data);

int	ft_check_cub(char *av)
{
	int	i;

	i = ft_strlen(av) - 1;
	if ((av[i] != 'b' || av[i - 1] != 'u' || \
	av[i - 2] != 'c' || av[i - 3] != '.'))
	{
		ft_putstr_fd("Map must be in .cub type\n", 2);
		exit (1);
	}
	return (0);
}

int	ft_check_arg(int ac, char **av)
{
	int	fd;

	if (ac != 2 || !av[1][0])
	{
		ft_dprintf(2, "Usage : ./cub3D map.cub\n");
		exit(1);
	}
	ft_check_cub(av[1]);
	fd = open(av[1], O_RDONLY | O_DIRECTORY, 0644);
	if (fd > 0)
	{
		ft_dprintf(2, "cub3D: %s: Is a directory\n", av[1]);
		close(fd);
		exit(1);
	}
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0)
	{
		perror("cub3D");
		exit (1);
	}
	close(fd);
	return (0);
}

void	ft_fill_map(t_map_data *data, char *file_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map = ft_split(file_data + data->map_index, '\n');
	data->map_max_x = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > data->map_max_x)
			data->map_max_x = ft_strlen(data->map[i]);
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W' || \
			data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				data->pos_player_x = j;
				data->pos_player_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	data->map_max_y = i;
}

int	ft_check_file(char **av, t_map_data *data, t_parse *parse)
{
	char	*file_data;

	file_data = ft_get_file(av[1]);
	if (!file_data)
	{
		ft_dprintf(2, "Error\nFile is empty\n");
		return (-1);
	}
	if (ft_check_file_data(data, file_data, parse))
	{
		ft_dprintf(2, "Error\nProblem with map's identifiers\n");
		ft_free_texture(data);
		free(file_data);
		return (-1);
	}
	if (ft_check_map(data, file_data))
	{
		ft_dprintf(2, "Error\nProblem with file's map\n");
		ft_free_texture(data);
		free(file_data);
		return (-1);
	}
	ft_fill_map(data, file_data);
	free(file_data);
	return (0);
}

int	ft_start(int ac, char **av, t_map_data *data, t_parse *parse)
{
	ft_check_arg(ac, av);
	if (ft_check_file(av, data, parse) == -1)
		exit (0);
	return (0);
}
