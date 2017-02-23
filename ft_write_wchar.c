/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:00:41 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 18:00:49 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_w(wchar_t c)
{
	char buff[5];

	(c < 0x80) ? write(1, &c, 1) : 0;
	if (c > 127 && c < 0x0800)
	{
		buff[0] = ((c >> 6) | 0xC0);
		buff[1] = ((c & 0x3F) | 0x80);
		write(1, buff, 2);
	}
	else if ((c > 0x07ff) && c < 0x10000)
	{
		buff[0] = ((c >> 12) | 0xE0);
		buff[1] = (((c >> 6) & 0x3F) | 0x80);
		buff[2] = ((c & 0x3F) | 0x80);
		write(1, buff, 3);
	}
	else if (c > 0xFFFF && c < 110000)
	{
		buff[0] = ((c >> 18)) | 0xF0;
		buff[1] = ((c >> 12) & 0x3F) | 0x80;
		buff[2] = ((c >> 6) & 0x3F) | 0x80;
		buff[3] = (c & 0x3F) | 0x80;
		write(1, buff, 4);
	}
}

int			ft_putchar_len(wchar_t c)
{
	char buff[5];

	if (c > 127 && c < 0x0800)
	{
		buff[0] = ((c >> 6) | 0xC0);
		buff[1] = ((c & 0x3F) | 0x80);
		return (2);
	}
	else if ((c > 0x07ff) && c < 0x10000)
	{
		buff[0] = ((c >> 12) | 0xE0);
		buff[1] = (((c >> 6) & 0x3F) | 0x80);
		buff[2] = ((c & 0x3F) | 0x80);
		return (3);
	}
	else if (c > 0xFFFF && c < 110000)
	{
		buff[0] = ((c >> 18)) | 0xF0;
		buff[1] = ((c >> 12) & 0x3F) | 0x80;
		buff[2] = ((c >> 6) & 0x3F) | 0x80;
		buff[3] = (c & 0x3F) | 0x80;
		return (4);
	}
	return (1);
}
