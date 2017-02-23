/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:29:28 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 11:33:11 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero(char **r)
{
	(*r) = malloc(2);
	(*r) = "0";
}

static void	f1(char **b, int *r)
{
	(*b) = malloc(17);
	(*b) = "0123456789ABCDEF";
	*r = 0;
}

static void	f2(unsigned long int *ch, int *rozr, int b, unsigned long int v)
{
	*ch = v;
	while (*ch > 0)
	{
		(*rozr)++;
		*ch = *ch / b;
	}
}

char		*ft_itoa_base_bu(unsigned long int value, int base)
{
	char				*r;
	char				*b16;
	unsigned long int	ch;
	int					rozr;

	if (value == 0)
	{
		zero(&r);
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
