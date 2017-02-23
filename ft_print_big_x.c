/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_big_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:54:23 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 11:56:50 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_x1(uintmax_t n, int *wid, t_format *f, char **v)
{
	int ii;

	*wid = max(ft_strlen(ft_itoa_base_m(n, 16)), f->width, f->prec);
	(*v) = (char *)malloc((*wid + 1) * sizeof(char));
	ii = *wid - ft_strlen(ft_itoa_base_m(n, 16));
	return (ii);
}

static void	f_x2(int *i, int ii, char **v, uintmax_t n)
{
	while (*i < ii)
	{
		(*v)[*i] = ' ';
		(*i)++;
	}
	(*v)[*i] = '\0';
	(*v) = ft_strjoin(*v, ft_itoa_base_m(n, 16));
}

static void	f_x3(int *j, int jj, char **v, int i)
{
	*j = 0;
	while (*j < jj)
	{
		(*v)[i - *j - 1] = '0';
		(*j)++;
	}
}

static void	f_x4(int i, int j, char **v)
{
	(*v)[i - j - 1] = 'X';
	(*v)[i - j - 2] = '0';
}

void		int_b0_big_x(uintmax_t n, t_format *f, char **v)
{
	int wid;
	int i;
	int ii;
	int j;
	int jj;

	i = 0;
	ii = f_x1(n, &wid, f, v);
	f_x2(&i, ii, v, n);
	jj = f->prec - ft_strlen(ft_itoa_base_m(n, 16));
	f_x3(&j, jj, v, i);
	if (i - j - 2 >= 0 && f->octo == 1 && f->nol == 0)
		f_x4(i, j, v);
	else if (f->octo == 1 && f->nol == 0)
		*v = ft_strjoin("0X", *v);
	if (f->nol == 1 && f->octo == 1 &&
			(size_t)(wid - 1) > ft_strlen(ft_itoa_base_m(n, 16)))
	{
		(*v)[0] = '0';
		(*v)[1] = 'X';
	}
	else if (f->nol == 1 && f->octo == 1)
		*v = ft_strjoin("0X", *v);
}
