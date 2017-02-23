/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:46:56 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/05 19:07:32 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	while (i < (int)n && p[i] != (unsigned char)c)
	{
		i++;
	}
	if (i == (int)n)
		return (NULL);
	return (p + i);
}
