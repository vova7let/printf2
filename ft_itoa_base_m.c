/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_m.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:37:11 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 11:38:59 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f1(char **b, int *r)
{
	(*b) = malloc(17);
	(*b) = "0123456789ABCDEF";
	*r = 0;
}

static void	f2(uintmax_t *ch, int *rozr, int b, uintmax_t v)
{
	*ch = v;
	while (*ch > 0)
	{
		(*rozr)++;
		*ch = *ch / b;
	}
}

char		*ft_itoa_base_m(uintmax_t value, int base)
{
	char		*r;
	char		*b16;
	uintmax_t	ch;
	int			rozr;

	if (value == 0)
	{
		r = malloc(2);
		r = "0";
		return (r);
	}
	f1(&b16, &rozr);
	f2(&ch, &rozr, base, value);
	r = (char *)malloc(rozr * (sizeof(char)) + 2);
	r[rozr] = '\0';
	while (value > 0)
	{
		r[rozr - 1] = b16[value % base];
		value = value / base;
		rozr--;
	}
	return (r);
}
