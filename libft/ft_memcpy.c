/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:43:35 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 18:51:04 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int				i;
	unsigned char	*p1;
	const char		*p2;

	i = 0;
	p1 = str1;
	p2 = str2;
	while (n)
	{
		p1[i] = (unsigned char)p2[i];
		n--;
		i++;
	}
	return (str1);
}
