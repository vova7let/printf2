/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:22:39 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/05 20:22:44 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_plus(int n)
{
	int		i;
	int		n1;
	char	*s;

	i = 0;
	n1 = n;
	while (n)
	{
		n = n / 10;
		i++;
	}
	s = (char *)malloc(i + 1);
	if (!s)
		return (0);
	s[i--] = '\0';
	while (i >= 0)
	{
		s[i--] = n1 % 10 + '0';
		n1 = n1 / 10;
	}
	return (s);
}

static char	*ft_null(int n)
{
	char	*s;

	if (n == 0)
	{
		s = (char *)malloc(2);
		if (!s)
			return (0);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	return (0);
}

static char	*ft_minus(int n)
{
	char	*s;
	int		n1;
	int		i;

	i = 0;
	n1 = n;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	s = (char *)malloc(i + 2);
	if (!s)
		return (0);
	s[i + 1] = '\0';
	s[0] = '-';
	while (i >= 1)
	{
		s[i--] = -(n1 % 10) + '0';
		n1 = n1 / 10;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	if (n > 0)
		return (ft_plus(n));
	else if (n < 0)
		return (ft_minus(n));
	else
		return (ft_null(n));
	return (0);
}
