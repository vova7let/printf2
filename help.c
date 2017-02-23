/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:11:01 by vshapran          #+#    #+#             */
/*   Updated: 2017/02/23 18:01:59 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help_me1(char **vivod, int *i, int *prob)
{
	if ((*vivod)[*i] == '0' && (*vivod)[*i + 1] == 'X')
	{
		write(1, "0X", 2);
		*i = *i + 2;
	}
	if ((*vivod)[*i] != ' ' && !((*vivod)[*i] == '0'
				&& (*vivod)[*i + 1] == 'X'))
	{
		write(1, &((*vivod)[*i]), 1);
		(*i)++;
	}
	else
	{
		(*prob)++;
		(*i)++;
	}
}

void	help_me2(char **vivod, int *i, int *prob)
{
	if ((*vivod)[*i] == '0' && (*vivod)[*i + 1] == 'x')
	{
		write(1, "0x", 2);
		*i = *i + 2;
	}
	if ((*vivod)[*i] != ' ' && !((*vivod)[*i] == '0'
				&& (*vivod)[*i + 1] == 'x'))
	{
		write(1, &((*vivod)[*i]), 1);
		(*i)++;
	}
	else
	{
		(*prob)++;
		(*i)++;
	}
}
