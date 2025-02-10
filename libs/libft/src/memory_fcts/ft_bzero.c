/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:41:07 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 16:01:13 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*str;

	str = (char *) s;
	cnt = 0;
	while (cnt < n)
	{
		str[cnt] = 0;
		cnt++;
	}
	s = (void *) str;
}
