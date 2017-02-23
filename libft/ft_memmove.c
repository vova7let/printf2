/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:51:39 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 18:55:07 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*p1;
	const char		*p2;
	size_t			i;

	p1 = str1;
	p2 = str2;
	i = 0;
	if (str2 < str1)
	{
		while (n != 0)
		{
			p1[n - 1] = (unsigned char)p2[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			p1[i] = (unsigned char)p2[i];
			i++;
		}
	}
	return (str1);
}
