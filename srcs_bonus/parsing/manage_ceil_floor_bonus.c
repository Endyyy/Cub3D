/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ceil_floor_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:23 by achretie          #+#    #+#             */
/*   Updated: 2023/04/06 12:21:11 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include "libft.h"

int	ft_check_id_nb(char *file_data, int i)
{
	int	values[3];
	int	cur_value;

	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	cur_value = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		if (file_data[i] >= '0' && file_data[i] <= '9')
			values[cur_value] = values[cur_value] * 10 + (file_data[i] - '0');
		else if (file_data[i] == ',')
			cur_value++;
		else
			return (-1);
		if (values[cur_value] > 255)
			return (-1);
		i++;
	}
	if (cur_value != 2)
		return (-1);
	return (i);
}

int	ft_get_rgb_value_ceil(t_map_data *data, char *file, int i, t_parse *parse)
{
	int	j;

	j = 0;
	if (parse->valid_ceil == 1)
		return (-1);
	data->ceil_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->ceil_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->ceil_color[j++] = ft_atoi(file + i);
	parse->valid_ceil = 1;
	return (0);
}

int	ft_get_rgb_value_floor(t_map_data *data, char *file, int i, t_parse *parse)
{
	int	j;

	j = 0;
	if (parse->valid_floor == 1)
		return (-1);
	data->floor_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->floor_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->floor_color[j++] = ft_atoi(file + i);
	parse->valid_floor = 1;
	return (0);
}

int	ft_manage_floor(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	stock;

	i += 2;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (file_data[i] == '\n')
		return (-1);
	stock = i;
	i = ft_check_id_nb(file_data, i);
	if (i == -1)
		return (-1);
	if (ft_get_rgb_value_floor(data, file_data, stock, parse) == -1)
		return (-1);
	return (i - 1);
}

int	ft_manage_ceiling(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	stock;

	i += 2;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (file_data[i] == '\n')
		return (-1);
	stock = i;
	i = ft_check_id_nb(file_data, i);
	if (i == -1)
		return (-1);
	if (ft_get_rgb_value_ceil(data, file_data, stock, parse) == -1)
		return (-1);
	return (i - 1);
}
