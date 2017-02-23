/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:02:47 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 18:08:39 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include "ft_printf.h"
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_format
{
	int	minus;
	int	plus;
	int	probel;
	int	octo;
	int	nol;
	int	type;
	int	width;
	int	prec;
	int	tochka;
	int	ttochka;
	int	p;
	int	none;
	int	ch;
}				t_format;
int				to_pr(t_format *f, char c, va_list ap);
void			func1(const char **format, t_format *f);
void			func2(const char **format, t_format *f);
void			func3(const char **format, t_format *f);
void			func4(const char **format, t_format *f, va_list ap, int *res);
void			func5(va_list ap, t_format *f, int *res, char c);
void			func6(va_list ap, t_format *f, int *res);
void			func7(va_list ap, t_format *f, int *res, char c);
void			func8(va_list ap, t_format *f, int *res, char c);
void			func0(const char **format, t_format *f, va_list ap, int *res);
void			ft_putchar_w(wchar_t c);
int				ft_nullstr(char *str, t_format frmt);
int				ft_putchar_len(wchar_t c);
int				print_wstr(va_list ar, t_format *f);
char			*ft_itoa_base(long long value, int base);
char			*ft_itoa_base_m(uintmax_t value, int base);
char			*ft_itoa_base_b(long long value, int base);
char			*ft_itoa_base_u(uintmax_t value, int base);
char			*ft_itoa_base_bu(unsigned long int value, int base);
int				print_u(va_list ap, t_format *f);
int				print_lu(va_list ap, t_format *f);
int				print_o(va_list ap, t_format *f);
int				print_lo(va_list ap, t_format *f);
int				print_c(va_list ap, t_format *f);
int				print_x(va_list ap, t_format *f);
int				print_s(va_list ap, t_format *f);
int				print_b(va_list ap, t_format *f);
int				print_procent(t_format *f);
int				print_wchar(va_list ar, t_format *f);
void			int_0_u(long long n, t_format *f, char **v);
void			int_0_b(long long n, t_format *f, char **v);
void			int_b0(long long n, t_format *f, char **v);
void			int_m0(long long n, t_format *f, char **v);
void			int_0(long long n, t_format *f, char **v);
int				print_d(va_list ap, t_format *f);
void			int_b0_b(unsigned long long n, t_format *f, char **v);
void			int_b0_u(long long n, t_format *f, char **v);
void			int_0_o(long long n, t_format *f, char **v);
void			int_b0_o(unsigned long long n, t_format *f, char **v);
void			int_0_c(int n, t_format *f, char **v);
void			int_b0_c(int n, t_format *f, char **v);
void			int_0_x(unsigned long n, t_format *f, char **v);
void			int_b0_x(unsigned long n, t_format *f, char **v);
void			int_b0_big_x(uintmax_t n, t_format *f, char **v);
void			int_0_big_x(uintmax_t n, t_format *f, char **v);
void			int_s(char *n, t_format *f, char **v);
int				print_big_x(va_list ap, t_format *f);
int				max(int a, int b, int c);
void			init_f(t_format **f);
void			help_me1(char **vivod, int *i, int *prob);
void			help_me2(char **vivod, int *i, int *prob);

#endif
