/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:36:19 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 17:36:23 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlenw(char *str)
{
	wchar_t	*put;
	int		i;

	i = 0;
	put = (wchar_t *)str;
	while (*put)
	{
		i += ft_putchar_len(*put);
		put++;
	}
	return (i);
}

static void	ft_putstrw(char *str, int i)
{
	wchar_t	*put;
	int		j;

	put = (wchar_t *)str;
	j = ft_putchar_len(*put);
	while (i >= j)
	{
		j += ft_putchar_len(*put);
		ft_putchar_w(*put);
		put++;
	}
}

static void	ft_ifput(t_format frmt, char *str, int len)
{
	int j;

	j = 0;
	if (frmt.minus != 0)
	{
		ft_putstrw(str, len);
		j = frmt.width - len;
		while (j-- > 0)
			write(1, " ", 1);
	}
	else
	{
		j = frmt.width - len;
		while (j-- > 0)
			frmt.nol > 0 ? write(1, "0", 1) : write(1, " ", 1);
		ft_putstrw(str, len);
	}
}

int			zerro(char *str, t_format frmt)
{
	wchar_t	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = (wchar_t *)str;
	while (*p)
	{
		j += ft_putchar_len(*p);
		if (j > frmt.prec)
			return (i);
		i = j;
		p++;
	}
	return (ft_strlenw((char *)p));
}

int			print_wstr(va_list ar, t_format *f)
{
	char	*str;
	wchar_t	*str2;
	int		i;

	i = 0;
	str2 = (wchar_t*)va_arg(ar, char*);
	if (str2 == NULL)
		return (ft_nullstr("(null)", *f));
	str = (char *)str2;
	i = ft_strlenw(str);
	(f->tochka == 1 && f->prec < ft_strlenw(str)) ? i = zerro(str, *f) : 0;
	if (f->width > i)
	{
		ft_ifput(*f, str, i);
		i = f->width;
	}
	else
		ft_putstrw((char *)str2, i);
	return (i);
}
