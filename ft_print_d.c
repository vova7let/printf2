/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:17:46 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 14:38:08 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_b0(long long n, t_format *f, char **v)
{
	int a[5];

	(f->minus == 1) ? f->nol = 0 : 0;
	(f->nol == 1 && f->probel == 1) ? (f->nol = 0) : 0;
	a[1] = 0;
	a[0] = max(ft_strlen(ft_itoa_base(n, 10)), f->width, f->prec);
	(*v) = (char *)malloc((a[0] + 1) * sizeof(char));
	a[2] = a[0] - ft_strlen(ft_itoa_base(n, 10));
	while (a[1] < a[2])
		(*v)[(a[1])++] = ' ';
	(*v)[a[1]] = '\0';
	(*v) = ft_strjoin(*v, ft_itoa_base(n, 10));
	a[4] = f->prec - ft_strlen(ft_itoa_base(n, 10));
	a[3] = 0;
	while (a[3] < a[4])
		(*v)[a[1] - (a[3])++ - 1] = '0';
	if (f->plus == 1 && a[1] - a[3] - 1 >= 0 && f->nol == 0)
		(*v)[a[1] - a[3] - 1] = '+';
	else if (f->plus == 1 && a[1] - a[3] - 1 >= 0 && f->nol == 1)
		(*v)[0] = '+';
	else if (f->plus == 1)
		(*v) = ft_strjoin("+", *v);
	if (f->probel == 1 && (*v)[0] != ' ' && f->plus != 1)
		(*v) = ft_strjoin(" ", *v);
}

void		int_m0(long long n, t_format *f, char **v)
{
	int			a[5];
	uintmax_t	nb;

	a[1] = 0;
	nb = n * (-1);
	(f->minus == 1) ? f->nol = 0 : 0;
	a[0] = max(ft_strlen(ft_itoa_base_m(nb, 10)), f->width, f->prec);
	(*v) = ft_memalloc(a[0] + 2);
	a[2] = a[0] - ft_strlen(ft_itoa_base_m(nb, 10));
	while (a[1] < a[2])
		(*v)[(a[1])++] = ' ';
	(*v)[a[1]] = '\0';
	(*v) = ft_strjoin(*v, ft_itoa_base_m(nb, 10));
	a[4] = f->prec - ft_strlen(ft_itoa_base_m(nb, 10));
	a[3] = 0;
	while (a[3] < a[4])
		(*v)[a[1] - (a[3])++ - 1] = '0';
	if (a[1] - a[3] - 1 >= 0 && f->nol == 0)
		(*v)[a[1] - a[3] - 1] = '-';
	else if (a[1] - a[3] - 1 >= 0 && f->nol == 1)
		(*v)[0] = '-';
	else
		(*v) = ft_strjoin("-", *v);
}

void		int_0(long long n, t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	wid = max(ft_strlen(ft_itoa_base(n, 10)), f->width, f->prec);
	(*v) = ft_memalloc(wid + 2);
	ii = wid - 1;
	while (i < ii)
		(*v)[i++] = ' ';
	(*v)[i] = '\0';
	if (!(n == 0 && f->tochka == 1 && f->prec == 0))
		(*v) = ft_strjoin(*v, ft_itoa_base(n, 10));
	jj = f->prec - ft_strlen(ft_itoa_base(n, 10));
	j = 0;
	while (j < jj)
		(*v)[i - j++ - 1] = '0';
	if (f->plus == 1 && i - j - 1 >= 0)
		(*v)[i - j - 1] = '+';
	else if (f->plus == 1)
		(*v) = ft_strjoin("+", *v);
	if (f->width > 0 && f->tochka == 1 && f->prec == 0)
		(*v) = ft_strjoin(*v, " ");
}

static void	f1(t_format *f, char **vivod)
{
	int i;

	if (f->nol == 1 && f->tochka == 0 && f->minus != 1)
	{
		i = 0;
		while ((*vivod)[i])
		{
			((*vivod)[i] == ' ') ? ((*vivod)[i] = '0') : 0;
			if ((*vivod)[i] == '+' && (*vivod)[i - 1] == '0')
			{
				(*vivod)[i - 1] = '+';
				(*vivod)[i] = '0';
			}
			i++;
		}
	}
}

int			print_d(va_list ap, t_format *f)
{
	char		*vivod;
	long long	n;

	f->type == 0 ? n = va_arg(ap, int) : 0;
	f->type == 2 ? n = (short)va_arg(ap, int) : 0;
	f->type == 1 ? n = (char)va_arg(ap, int) : 0;
	f->type > 2 ? n = va_arg(ap, long long) : 0;
	(f->plus == 1) ? (f->probel = 0) : 0;
	if (n > 0)
		int_b0(n, f, &vivod);
	else if (n < 0)
		int_m0(n, f, &vivod);
	else if (n == 0)
		int_0(n, f, &vivod);
	if (f->minus == 1)
		while (*vivod == ' ')
		{
			vivod = ft_strjoin(vivod, " ");
			vivod++;
		}
	f1(f, &vivod);
	(f->probel == 1 && n == 0) ? (vivod[0] = ' ') : 0;
	(vivod != NULL) ? (ft_putstr(vivod)) : 0;
	return (ft_strlen(vivod));
}
