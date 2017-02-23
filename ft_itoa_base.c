/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:46:51 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 11:49:36 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero(char **r)
{
	(*r) = malloc(2);
	(*r) = "0";
}

static void	f2(char **b, int *r, long long *ch, long long value)
{
	(*b) = malloc(17);
	(*b) = "0123456789abcdef";
	*r = 0;
	*ch = value;
}

static void	f1(int *rozr, long long *value, long long *ch, int base)
{
	if (*value < 0)
	{
		(*rozr)++;
		(*value) = (*value) * (-1);
		*ch = *value;
	}
	while (*ch > 0)
	{
		(*rozr)++;
		*ch = (*ch) / base;
	}
}

char		*ft_itoa_base(long long value, int base)
{
	char		*r;
	char		*b16;
	long long	ch2;
	long long	ch;
	int			rozr;

	if (value == 0)
	{
		zero(&r);
		return (r);
	}
	f2(&b16, &rozr, &ch, value);
	ch2 = value;
	f1(&rozr, &value, &ch, base);
	r = (char *)malloc(rozr * (sizeof(char)) + 2);
	r[rozr] = '\0';
	while (value > 0)
	{
		r[rozr - 1] = b16[value % base];
		value = value / base;
		rozr--;
	}
	if (ch2 < 0)
		r[0] = '-';
	return (r);
}
