/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:27:17 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 13:58:29 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						int_b0_b(unsigned long long n,
							t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	wid = max(ft_strlen(ft_itoa_base_m(n, 2)), f->width, f->prec);
	(*v) = (char *)malloc((wid + 1) * sizeof(char));
	ii = wid - ft_strlen(ft_itoa_base_m(n, 2));
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
	(*v) = ft_strjoin(*v, ft_itoa_base_m(n, 2));
	jj = f->prec - ft_strlen(ft_itoa_base_m(n, 2));
	j = 0;
	while (j < jj)
		(*v)[i - j++ - 1] = '0';
}

static unsigned long long	f1(va_list ap, t_format *f)
{
	unsigned long long	n;

	f->type == 0 ? n = va_arg(ap, unsigned int) : 0;
	f->type == 2 ? n = (unsigned short)va_arg(ap, unsigned int) : 0;
	f->type == 1 ? n = (unsigned char)va_arg(ap, unsigned int) : 0;
	f->type > 2 ? n = va_arg(ap, unsigned long long) : 0;
	return (n);
}

void						int_0_b(long long n, t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	wid = max(ft_strlen(ft_itoa_base_m(n, 2)), f->width, f->prec);
	(*v) = ft_memalloc(wid + 2);
	ii = wid - 1;
	while (i < ii)
		(*v)[i++] = ' ';
	(*v)[i] = '\0';
	if (!(n == 0 && f->tochka == 1 && f->prec == 0) || f->octo == 1)
		(*v) = ft_strjoin(*v, ft_itoa_base_m(n, 2));
	jj = f->prec - ft_strlen(ft_itoa_base_m(n, 2));
	j = 0;
	while (j < jj)
		(*v)[i - j++ - 1] = '0';
	if (f->width > 0 && f->tochka == 1 && f->prec == 0)
		(*v) = ft_strjoin(*v, " ");
}

static void					f2(t_format *f, char **vivod)
{
	if (f->minus == 1)
	{
		while (**vivod == ' ')
		{
			*vivod = ft_strjoin(*vivod, " ");
			(*vivod)++;
		}
	}
}

int							print_b(va_list ap, t_format *f)
{
	int					i;
	char				*vivod;
	unsigned long long	n;

	n = f1(ap, f);
	if (n > 0)
		int_b0_b(n, f, &vivod);
	else if (n == 0)
		int_0_b(n, f, &vivod);
	f2(f, &vivod);
	if (f->nol == 1 && f->tochka == 0 && f->minus != 1)
	{
		i = 0;
		while (vivod[i])
		{
			if (vivod[i] == ' ')
				vivod[i] = '0';
			i++;
		}
	}
	if (vivod != NULL)
		ft_putstr(vivod);
	return (ft_strlen(vivod));
}
