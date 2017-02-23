/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:13:20 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 19:28:29 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t l)
{
	int	i;
	int	f;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		f = 0;
		while (to_find[f] == str[i + f] && to_find[f] != '\0' && f + i < (int)l)
		{
			if (f == 0)
				j = i;
			f++;
		}
		if (to_find[f] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
