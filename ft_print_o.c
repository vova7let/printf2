/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:54:56 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 15:07:41 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f1(t_format *f, char **vivod)
{
	int i;

	if (f->nol == 1 && f->tochka == 0 && f->minus != 1)
	{
		i = 0;
		while ((*vivod)[i])
		{
			if ((*vivod)[i] == ' ')
				(*vivod)[i] = '0';
			i++;
		}
	}
}

void		int_b0_o(unsigned long long n, t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	wid = max(ft_strlen(ft_itoa_base_m(n, 8)), f->width, f->prec);
	(*v) = (char *)malloc((wid + 1) * sizeof(char));
	ii = wid - ft_strlen(ft_itoa_base_m(n, 8));
	while (i < ii - 1)
		(*v)[i++] = ' ';
	if (f->octo == 1 && i < ii)
		(*v)[i] = '0';
	else if (f->octo == 1)
		*v = ft_strjoin("0", *v);
	else if (i < ii)
		(*v)[i] = ' ';
	i++;
	(*v)[i] = '\0';
	(*v) = ft_strjoin(*v, ft_itoa_base_m(n, 8));
	jj = f->prec - ft_strlen(ft_itoa_base_m(n, 8));
	j = 0;
	while (j < jj)
		(*v)[i - j++ - 1] = '0';
}

void		int_0_o(long long n, t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	wid = max(ft_strlen(ft_itoa_base_m(n, 8)), f->width, f->prec);
	(*v) = ft_memalloc(wid + 2);
	ii = wid - 1;
	while (i < ii)
		(*v)[i++] = ' ';
	(*v)[i] = '\0';
	if (!(n == 0 && f->tochka == 1 && f->prec == 0) || f->octo == 1)
		(*v) = ft_strjoin(*v, ft_itoa_base_m(n, 8));
	jj = f->prec - ft_strlen(ft_itoa_base_m(n, 8));
	j = 0;
	while (j < jj)
		(*v)[i - j++ - 1] = '0';
	if (f->width > 0 && f->tochka == 1 && f->prec == 0)
		(*v) = ft_strjoin(*v, " ");
}

int			print_o(va_list ap, t_format *f)
{
	char				*vivod;
	unsigned long long	n;

	f->type == 0 ? n = va_arg(ap, unsigned int) : 0;
	f->type == 2 ? n = (unsigned short)va_arg(ap, unsigned int) : 0;
	f->type == 1 ? n = (unsigned char)va_arg(ap, unsigned int) : 0;
	f->type > 2 ? n = va_arg(ap, unsigned long long) : 0;
	if (n > 0)
		int_b0_o(n, f, &vivod);
	else if (n == 0)
		int_0_o(n, f, &vivod);
	if (f->minus == 1)
		while (*vivod == ' ')
		{
			vivod = ft_strjoin(vivod, " ");
			vivod++;
		}
	f1(f, &vivod);
	(vivod != NULL) ? (ft_putstr(vivod)) : 0;
	return (ft_strlen(vivod));
}

int			print_lo(va_list ap, t_format *f)
{
	char				*vivod;
	unsigned long long	n;

	n = va_arg(ap, unsigned long);
	if (n > 0)
		int_b0_o(n, f, &vivod);
	else if (n == 0)
		int_0_o(n, f, &vivod);
	if (f->minus == 1)
		while (*vivod == ' ')
		{
			vivod = ft_strjoin(vivod, " ");
			vivod++;
		}
	f1(f, &vivod);
	(vivod != NULL) ? (ft_putstr(vivod)) : 0;
	return (ft_strlen(vivod));
}
