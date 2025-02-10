/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:42:12 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/09 08:33:12 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isext(char *file, char *ext)
{
	int	l_ext;
	int	l_file;

	if (!file || !ext)
		return (0);
	l_ext = ft_strlen(ext);
	l_file = ft_strlen(file);
	if (l_ext >= l_file)
		return (0);
	return (ft_strncmp(file + l_file - l_ext, ext, l_ext) == 0
		&& file[l_file - l_ext - 1] != '/');
}
