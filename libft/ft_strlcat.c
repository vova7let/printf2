/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:05:46 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 19:07:13 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	dl = 0;
	sl = 0;
	i = 0;
	while (dest[dl] != '\0')
		dl++;
	while (src[sl] != '\0')
		sl++;
	if (nb < dl)
		return (nb + sl);
	i = 0;
	while (src[i] != '\0' && dl + i < nb - 1)
	{
		dest[dl + i] = src[i];
		i++;
	}
	dest[dl + i] = '\0';
	return (sl + dl);
}
