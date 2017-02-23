/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:07:08 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/02 22:11:35 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*data;

	data = ft_memalloc(content_size + sizeof(content));
	if (!data)
		return (NULL);
	if (!content)
	{
		lst = malloc(sizeof(t_list));
		lst->next = NULL;
		lst->content = NULL;
		lst->content_size = 0;
		return (lst);
	}
	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	ft_memcpy(data, content, content_size);
	lst->next = NULL;
	lst->content = data;
	lst->content_size = content_size;
	return (lst);
}
