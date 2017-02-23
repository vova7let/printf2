/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:57:10 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 17:58:09 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_f(t_format **f)
{
	(*f) = (t_format *)malloc(sizeof(t_format));
	(*f)->tochka = 0;
	(*f)->minus = 0;
	(*f)->plus = 0;
	(*f)->probel = 0;
	(*f)->octo = 0;
	(*f)->nol = 0;
	(*f)->type = 0;
	(*f)->width = 0;
	(*f)->prec = 0;
	(*f)->ttochka = 0;
	(*f)->p = 0;
	(*f)->none = 0;
	(*f)->ch = 0;
}

int		max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else if (c >= a && c >= b)
		return (c);
	else
		return (a);
}

void	func5(va_list ap, t_format *f, int *res, char c)
{
	if (c == '%')
		*res = print_procent(f);
	else if (c == 'd' || c == 'i')
		*res = print_d(ap, f);
	else if (c == 'u')
		*res = print_u(ap, f);
	else if (c == 'b')
		*res = print_b(ap, f);
	else if (c == 'U')
		*res = print_lu(ap, f);
	else if (c == 'o')
		*res = print_o(ap, f);
	else if (c == 'D')
	{
		f->type = 4;
		*res = print_d(ap, f);
	}
}

void	func6(va_list ap, t_format *f, int *res)
{
	f->p = 1;
	f->octo = 1;
	f->type = 5;
	*res = print_x(ap, f);
}

void	func7(va_list ap, t_format *f, int *res, char c)
{
	f->none = 1;
	f->ch = c;
	*res = print_c(ap, f);
}
