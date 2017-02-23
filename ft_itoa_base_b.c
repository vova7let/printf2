/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:11:01 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 11:22:03 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		zero(char **r)
{
	(*r) = malloc(2);
	(*r) = "0";
}

static void		f1(char **b, int *r)
{
	(*b) = malloc(17);
	(*b) = "0123456789ABCDEF";
	*r = 0;
}

static void		f2(long long *value, int *rozr, long long *ch, int base)
{
	*ch = *value;
	if (*value < 0)
	{
		(*rozr)++;
		*value = (*value) * (-1);
		*ch = *value;
	}
	while (*ch > 0)
	{
		(*rozr)++;
		*ch = *ch / base;
	}
}

char			*ft_itoa_base_b(long long value, int base)
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
	f1(&b16, &rozr);
	ch2 = value;
	f2(&value, &rozr, &ch, base);
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
