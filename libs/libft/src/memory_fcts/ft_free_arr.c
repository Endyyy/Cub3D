/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:07:30 by alouis-j          #+#    #+#             */
/*   Updated: 2023/01/02 14:45:37 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Function that will free ptr[0] to ptr[n] if ptr[n+1] == NULL it will also
 * free ptr **/

#include "../libft.h"

void	ft_free_arr(void **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
