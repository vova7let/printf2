/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:26:06 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/05 19:09:18 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
