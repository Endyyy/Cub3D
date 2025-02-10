/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:55:10 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 16:00:14 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_backup;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lst_backup = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_backup;
	}
}
