/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:21:17 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 16:17:50 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	char	*last_chr;

	s_cpy = (char *) s;
	last_chr = NULL;
	while (c > 255)
		c -= 256;
	while (*s_cpy)
	{
		if (*s_cpy == c)
			last_chr = s_cpy;
		s_cpy++;
	}
	if (c == 0)
		return (s_cpy);
	return (last_chr);
}
