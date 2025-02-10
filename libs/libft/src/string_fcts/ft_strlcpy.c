/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:35:22 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/22 17:03:15 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	cnt;

	cnt = 0;
	while (cnt + 1 < (int)size && src[cnt])
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	if (size)
		dst[cnt] = 0;
	return (ft_strlen(src));
}
