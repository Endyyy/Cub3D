/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:23 by achretie          #+#    #+#             */
/*   Updated: 2023/04/05 11:08:25 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include <fcntl.h>
#include "libft.h"

char	**ft_add_border(int max_w, int max_l, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < max_l + 5)
	{
		while (j < max_w + 4)
		{
			if (i == 0 || i == max_l + 4 || j == 0 || j == max_w + 3)
				map[i][j] = '1';
			else
				map[i][j] = ' ';
			j++;
		}
		i++;
		j = 0;
	}
	return (map);
}

char	**ft_fill_middle(char *file, char **map, t_map_data *data)
{
	int	i;
	int	j;
	int	x;

	x = data->map_index;
	i = 2;
	j = 2;
	while (file[x])
	{
		if (file[x] == '\n')
		{
			j = 1;
			i++;
		}
		else
			map[i][j] = file[x];
		x++;
		j++;
	}
	return (map);
}

int	ft_check_valid_char(char *file_data, int i)
{
	if (file_data[i] != '\n' && file_data[i] != 'N' && \
		file_data[i] != 'S' && file_data[i] != 'E' && \
		file_data[i] != 'W' && file_data[i] != ' ' && \
		file_data[i] != '0' && file_data[i] != '1')
		return (1);
	return (0);
}

char	*ft_get_file(char *arg)
{
	int		fd;
	char	*file;
	char	*stock;
	char	*tmp;

	fd = open(arg, O_RDONLY, 0644);
	file = get_next_line(fd);
	if (!file)
		return (NULL);
	while (1)
	{
		stock = get_next_line(fd);
		if (!stock)
			break ;
		tmp = ft_strdup(file);
		free(file);
		file = ft_strjoin(tmp, stock);
		free(tmp);
		free(stock);
	}
	close(fd);
	return (file);
}
