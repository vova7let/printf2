/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:50:10 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 17:53:06 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		to_pr(t_format *f, char c, va_list ap)
{
	int res;

	res = 0;
	if (c == '%' || c == 'd' || c == 'i' || c == 'u' || c == 'b' ||
			c == 'U' || c == 'o' || c == 'D')
		func5(ap, f, &res, c);
	else if (c == 'O')
		res = print_lo(ap, f);
	else if (c == 's' && f->type < 3)
		res = print_s(ap, f);
	else if (c == 'c' && f->type < 3)
		res = print_c(ap, f);
	else if (c == 'x')
		res = print_x(ap, f);
	else if (c == 'X')
		res = print_big_x(ap, f);
	else if (c == 'p')
		func6(ap, f, &res);
	else if (c == 'C' || c == 'c' || c == 'S' || c == 's')
		func8(ap, f, &res, c);
	else if (c != '\0')
		func7(ap, f, &res, c);
	else
		return (0);
	return (res);
}

void	func0(const char **format, t_format *f, va_list ap, int *res)
{
	init_f(&f);
	(*format)++;
	while (**format != '\0')
	{
		if (ft_strrchr("-+ #0jz", **format) != NULL)
			func1(format, f);
		else if (ft_strrchr("lh", **format) != NULL)
			func2(format, f);
		else if ((**format > '0' && **format <= '9') || **format == '.')
			func3(format, f);
		else
		{
			func4(format, f, ap, res);
			break ;
		}
	}
	ft_memdel((void **)&f);
}

int		ft_printf(const char *format, ...)
{
	int			res;
	t_format	*f;
	va_list		ap;

	res = 0;
	f = NULL;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			func0(&format, f, ap, &res);
		else
		{
			res++;
			write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (res);
}
