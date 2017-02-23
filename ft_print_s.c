/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:32:42 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 15:43:57 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

static void	f1(t_format *f, char **v, char *n, int *m)
{
	int wid;
	int i;
	int j;

	i = 0;
	j = 0;
	wid = max(min(ft_strlen(n), f->prec), f->width, 0);
	(*v) = malloc(wid + 1);
	while (i + (f->none == 1 ? 1 : 0) < wid - min(ft_strlen(n), f->prec))
	{
		(*v)[i] = ' ';
		i++;
	}
	*m = i;
	while (i < wid && n[j] != '\0')
	{
		(*v)[i] = n[j];
		i++;
		j++;
	}
	(*v)[i] = '\0';
}

static void	f2(t_format *f, char **v, char *n, int *m)
{
	int wid;
	int i;
	int j;

	i = 0;
	j = 0;
	wid = max(ft_strlen(n), f->width, 0);
	(*v) = malloc(wid + 1);
	while (i + (f->none == 1 ? 1 : 0) < (int)(wid - ft_strlen(n)))
	{
		(*v)[i] = ' ';
		i++;
	}
	*m = i;
	while (i < wid)
	{
		(*v)[i] = n[j];
		i++;
		j++;
	}
	(*v)[i] = '\0';
}

void		int_s(char *n, t_format *f, char **v)
{
	int m;

	m = 0;
	if (f->tochka == 1)
		f1(f, v, n, &m);
	else
		f2(f, v, n, &m);
	if (f->minus == 1)
	{
		while (m > 0)
		{
			(*v) = ft_strjoin(*v, " ");
			(*v)++;
			m--;
		}
	}
}

int			print_s(va_list ap, t_format *f)
{
	int		i;
	char	*vivod;
	char	*n;

	i = 0;
	if (f->none == 0)
		n = va_arg(ap, char*);
	else
	{
		n = malloc(1);
		n = "";
	}
	if (n == NULL)
	{
		n = malloc(7);
		n = "(null)";
	}
	int_s(n, f, &vivod);
	if (f->nol == 1)
		while (vivod[i] == ' ')
			vivod[i++] = '0';
	if (vivod != NULL)
		ft_putstr(vivod);
	return (ft_strlen(vivod));
}
