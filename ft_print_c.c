/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:59:47 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 14:01:35 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_ifputchar(t_format *f, int str, int i, int len)
{
	if (f->minus != 0)
	{
		write(1, &str, 1);
		i = f->width - len;
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = f->width - len;
		while (i-- > 0)
			f->nol == 1 ? write(1, "0", 1) : write(1, " ", 1);
		write(1, &str, 1);
	}
}

int				print_c(va_list ap, t_format *f)
{
	int str;
	int len;
	int i;

	i = 0;
	if (f->none == 0)
		str = va_arg(ap, int);
	else
		str = f->ch;
	len = 1;
	if (f->width > len)
	{
		ft_ifputchar(f, str, i, len);
		len = f->width;
	}
	else
		write(1, &str, 1);
	return (len);
}

int				print_procent(t_format *f)
{
	int str;
	int len;
	int i;

	i = 0;
	str = 37;
	len = 1;
	if (f->width > len)
	{
		ft_ifputchar(f, str, i, len);
		len = f->width;
	}
	else
		write(1, &str, 1);
	return (len);
}
