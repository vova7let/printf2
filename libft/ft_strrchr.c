/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:26:00 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 19:27:40 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0 && str[i] != (char)n)
	{
		i--;
	}
	if (str[i] == (char)n)
		return ((char *)str + i);
	return (NULL);
}
