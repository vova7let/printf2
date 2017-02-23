/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:35:53 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 17:35:59 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ifputchar(t_format frmt, wchar_t c, int i, int len)
{
	if (frmt.minus != 0)
	{
		ft_putchar_w(c);
		i = frmt.width - len;
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = frmt.width - len;
		while (i-- > 0)
			frmt.nol > 0 ? write(1, "0", 1) : write(1, " ", 1);
		ft_putchar_w(c);
	}
}

int			print_wchar(va_list ar, t_format *f)
{
	wchar_t	c;
	int		len;
	int		i;

	i = 0;
	c = (wchar_t)va_arg(ar, int);
	len = ft_putchar_len(c);
	if (f->width > len)
	{
		ft_ifputchar(*f, c, i, len);
		len = f->width;
	}
	else
		ft_putchar_w(c);
	return (len);
}
