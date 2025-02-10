/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:38:46 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 16:00:38 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ptr_last = lst;
		lst = lst->next;
	}
	return (ptr_last);
}
