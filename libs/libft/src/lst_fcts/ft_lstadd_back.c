/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:49:54 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 15:59:55 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_backup;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_backup = *lst;
	while ((*lst)->next)
		*(lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = lst_backup;
}
