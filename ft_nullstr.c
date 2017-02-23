/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:39:35 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 18:39:39 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_ifput(t_format frmt, char *str, int i, int len)
{
	if (frmt.minus != 0)
	{
		ft_putstr(str);
		i = frmt.width - len;
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		i = frmt.width - len;
		while (i-- > 0)
			frmt.nol > 0 ? write(1, "0", 1) : write(1, " ", 1);
		ft_putstr(str);
	}
}

int				ft_nullstr(char *str, t_format frmt)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	(frmt.prec > 0 && (size_t)(frmt.prec) < ft_strlen(str))
		? str[frmt.prec] = '\0' : 0;
	len = ft_strlen(str);
	if (frmt.width > len)
	{
		ft_ifput(frmt, str, i, len);
		len = frmt.width;
	}
	else
		ft_putstr(str);
	return (len);
}
