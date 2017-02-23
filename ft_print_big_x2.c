/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 10:38:34 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 17:38:39 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				int_0_big_x(uintmax_t n, t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	wid = max(ft_strlen(ft_itoa_base_m(n, 16)), f->width, f->prec);
	(*v) = ft_memalloc(wid + 2);
	ii = wid - 1;
	while (i < ii)
	{
		(*v)[i] = ' ';
		i++;
	}
	(*v)[i] = '\0';
	if (!(n == 0 && f->tochka == 1 && f->prec == 0))
		(*v) = ft_strjoin(*v, ft_itoa_base_m(n, 16));
	jj = f->prec - ft_strlen(ft_itoa_base_m(n, 16));
	j = 0;
	while (j++ < jj)
		(*v)[i - j - 1] = '0';
	if (f->width > 0 && f->tochka == 1 && f->prec == 0)
		(*v) = ft_strjoin(*v, " ");
}

static uintmax_t	f1(va_list ap, t_format *f)
{
	uintmax_t n;

	f->type == 0 ? n = va_arg(ap, unsigned int) : 0;
	f->type == 2 ? n = (unsigned short)va_arg(ap, unsigned int) : 0;
	f->type == 1 ? n = (unsigned char)va_arg(ap, unsigned int) : 0;
	f->type > 2 ? n = va_arg(ap, uintmax_t) : 0;
	return (n);
}

static void			f2(char **vivod, t_format *f)
{
	int	i;
	int	prob;

	if (*vivod != NULL && f->octo == 1 && f->minus == 1)
	{
		prob = 0;
		i = 0;
		while ((*vivod)[i])
			help_me1(vivod, &i, &prob);
		while (prob > 0)
		{
			write(1, " ", 1);
			prob--;
		}
	}
}

static void			f3(t_format *f, char **v)
{
	int i;

	if (f->nol == 1 && f->tochka == 0 && f->minus != 1)
	{
		i = 0;
		while ((*v)[i])
		{
			if ((*v)[i] == ' ')
				(*v)[i] = '0';
			i++;
		}
	}
}

int					print_big_x(va_list ap, t_format *f)
{
	char		*vivod;
	uintmax_t	n;

	n = f1(ap, f);
	if (n > 0)
		int_b0_big_x(n, f, &vivod);
	else if (n == 0)
		int_0_big_x(n, f, &vivod);
	if (f->minus == 1 && f->octo != 1)
		while (*vivod == ' ')
		{
			vivod = ft_strjoin(vivod, " ");
			vivod++;
		}
	f3(f, &vivod);
	if (vivod != NULL && (f->octo != 1 || f->minus != 1))
		ft_putstr(vivod);
	f2(&vivod, f);
	return (ft_strlen(vivod));
}
