/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:11:37 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/07 09:56:34 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}	
	while (str[cnt])
	{
		write(fd, &str[cnt], 1);
		cnt++;
	}
	return (cnt);
}
