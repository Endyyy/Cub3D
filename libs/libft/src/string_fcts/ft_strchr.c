/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:33:59 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 16:17:31 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = (char *) s;
	while (c > 255)
		c -= 256;
	while (*str)
	{
		if (*str == c)
			return (str + cnt);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}
