/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:11:15 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/22 17:06:54 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*fin_str;
	int		cnt;

	if (!s)
		return (NULL);
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	if ((int)start + (int)len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if ((int)start >= ft_strlen(s))
	{
		fin_str = (char *)malloc(1);
		if (!fin_str)
			return (NULL);
		*fin_str = 0;
		return (fin_str);
	}
	fin_str = (char *)ft_calloc(len + 1, 1);
	if (!fin_str)
		return (NULL);
	s += start;
	cnt = -1;
	while (s[++cnt] && cnt < (int)len)
		fin_str[cnt] = s[cnt];
	return (fin_str);
}
