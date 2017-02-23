/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:39:45 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 17:42:59 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_x1(uintmax_t n, int *wid, t_format *f, char **v)
{
	int ii;

	*wid = max(ft_strlen(ft_itoa_base_u(n, 16)), f->width, f->prec);
	(*v) = (char *)malloc((*wid + 1) * sizeof(char));
	ii = *wid - ft_strlen(ft_itoa_base_u(n, 16));
	return (ii);
}

static void	f_x2(int *i, int ii, char **v)
{
	*i = 0;
	while (*i < ii)
	{
		(*v)[*i] = ' ';
		(*i)++;
	}
	(*v)[*i] = '\0';
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
	(*v)[i - j - 1] = 'x';
	(*v)[i - j - 2] = '0';
}

void		int_b0_x(uintmax_t n, t_format *f, char **v)
{
	int	wid;
	int	i;
	int	ii;
	int	j;
	int	jj;

	ii = f_x1(n, &wid, f, v);
	(f->p == 1 && f->width == 13) ? (ii--) : 0;
	f_x2(&i, ii, v);
	if (!(f->p == 1 && n == 0 && f->tochka == 1 && f->prec == 0))
		(*v) = ft_strjoin(*v, ft_itoa_base_u(n, 16));
	jj = f->prec - ft_strlen(ft_itoa_base_u(n, 16));
	f_x3(&j, jj, v, i);
	if (i - j - 2 >= 0 && f->octo == 1 && f->nol == 0)
		f_x4(i, j, v);
	else if (f->octo == 1 && f->nol == 0)
		*v = ft_strjoin("0x", *v);
	if (f->nol == 1 && f->octo == 1 &&
		(size_t)(wid - 1) > ft_strlen(ft_itoa_base_u(n, 16)))
	{
		(*v)[0] = '0';
		(*v)[1] = 'x';
	}
	else if (f->nol == 1 && f->octo == 1)
		*v = ft_strjoin("0x", *v);
}
