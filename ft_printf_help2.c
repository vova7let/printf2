/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:58:38 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 18:00:07 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	func8(va_list ap, t_format *f, int *res, char c)
{
	if (c == 'C' || (c == 'c' && f->type > 2))
		*res = print_wchar(ap, f);
	else if (c == 'S' || (c == 's' && f->type > 2))
		*res = print_wstr(ap, f);
}

void	func1(const char **format, t_format *f)
{
	(**format == '-') ? f->minus = 1 : 0;
	(**format == '+') ? f->plus = 1 : 0;
	(**format == ' ') ? f->probel = 1 : 0;
	(**format == '#') ? f->octo = 1 : 0;
	(**format == '0') ? f->nol = 1 : 0;
	if (**format == 'j')
		(f->type <= 2) ? f->type = 5 : 0;
	if (**format == 'z')
		(f->type <= 2) ? f->type = 6 : 0;
	(*format)++;
}

void	func2(const char **format, t_format *f)
{
	if (**format == 'l' && *(*format + 1) != 'l')
	{
		(f->type <= 2) ? f->type = 3 : 0;
		(*format)++;
	}
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		(f->type == 0) ? f->type = 1 : 0;
		*format = *format + 2;
	}
	else if (**format == 'h' && *(*format + 1) != 'h')
	{
		(f->type <= 1) ? f->type = 2 : 0;
		(*format)++;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		(f->type <= 2) ? f->type = 4 : 0;
		*format = *format + 2;
	}
}

void	func3(const char **format, t_format *f)
{
	if (**format > '0' && **format <= '9')
	{
		f->width = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	else if (**format == '.')
	{
		(*format)++;
		f->tochka = 1;
		f->prec = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
}

void	func4(const char **format, t_format *f, va_list ap, int *res)
{
	if (ft_strrchr("diUuOoXxsc%pDSCb", **format) != NULL)
	{
		*res = *res + to_pr(f, **format, ap);
		(*format)++;
	}
	else
	{
		f->none = 1;
		f->ch = **format;
		*res = *res + to_pr(f, **format, ap);
		(*format)++;
	}
}
