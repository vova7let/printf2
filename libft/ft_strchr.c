/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:58:33 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 18:59:48 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && str[i] != (char)n)
	{
		i++;
	}
	if (str[i] == (char)n)
		return ((char *)str + i);
	return (NULL);
}
