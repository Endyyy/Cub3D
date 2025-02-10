/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouis-j <alouis-j@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:34:15 by alouis-j          #+#    #+#             */
/*   Updated: 2022/11/05 16:00:30 by alouis-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_backup;

	if (!lst || !f)
		return ;
	lst_backup = lst;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = lst_backup;
}
