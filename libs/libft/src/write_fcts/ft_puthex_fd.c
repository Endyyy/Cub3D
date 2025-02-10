/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:18:32 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/07 10:02:32 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex_fd(unsigned long n, int lowcase, int cnt, int fd)
{
	char		to_wrt;
	char		*base;

	base = "0123456789abcdef";
	if (!lowcase)
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		cnt += ft_puthex_fd(n / 16, lowcase, 0, fd);
		cnt += ft_puthex_fd(n % 16, lowcase, 0, fd);
	}
	else
	{
		to_wrt = base[n];
		write(fd, &to_wrt, 1);
		cnt++;
	}
	return (cnt);
}
