/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:48:55 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 18:50:31 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)str1;
	p2 = (unsigned char*)str2;
	while (n)
	{
		if (*p1++ != *p2++)
			return (*(p1 - 1) - *(p2 - 1));
		n--;
	}
	return (0);
}
