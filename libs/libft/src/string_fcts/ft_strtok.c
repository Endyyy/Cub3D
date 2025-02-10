/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:07:30 by alouis-j          #+#    #+#             */
/*   Updated: 2022/12/12 16:07:13 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*buf = NULL;

	if (str)
		buf = str;
	if (!buf || !delim)
		return (NULL);
	while (*buf && ft_strchr(delim, *buf))
		buf++;
	str = buf;
	if (!*str)
		return (NULL);
	while (*buf && !ft_strchr(delim, *buf))
		buf++;
	if (*buf)
		*buf++ = 0;
	if (!*buf)
		buf = NULL;
	return (str);
}
