/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:57:50 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 19:34:56 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	r = (char *)malloc(i + 1);
	i = 0;
	if (s && f && r)
	{
		while (s[i])
		{
			r[i] = f(i, s[i]);
			i++;
		}
		r[i] = '\0';
	}
	else
		return (NULL);
	return (r);
}
