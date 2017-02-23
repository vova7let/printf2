/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:21:45 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 19:23:01 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	first;

	i = 0;
	if (str[i] == '\0' && to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		first = 0;
		while (to_find[first] == str[i + first] && to_find[first] != '\0')
			first++;
		if (to_find[first] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
