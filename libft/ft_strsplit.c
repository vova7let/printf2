/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshapran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:36:41 by vshapran          #+#    #+#             */
/*   Updated: 2016/12/01 19:25:31 by vshapran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_separator(char c, char s)
{
	int	b;

	b = 0;
	if (c == s)
		b++;
	return (b);
}

static int		count(const char *str, char c)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		while (str[i] && !is_separator(str[i], c))
		{
			i++;
			flag = 1;
		}
		if (str[i] && is_separator(str[i], c))
		{
			if (flag == 1)
				j++;
			flag = 0;
			i++;
		}
	}
	return (j + 2);
}

static int		nbr(int i, const char *str, char c)
{
	int j;

	j = 0;
	while (str[i] && !is_separator(str[i], c))
	{
		i++;
		j++;
	}
	return (j);
}

static char		**norm(const char *str, char **new, char c)
{
	int j;
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		while (is_separator(str[i], c) && str[i] != '\0')
			i++;
		if (str[i])
		{
			j = 0;
			new[x] = malloc(sizeof(char*) * (nbr(i, str, c)));
			while (str[i] && !is_separator(str[i], c))
				new[x][j++] = str[i++];
			new[x++][j] = '\0';
		}
	}
	new[x] = 0;
	return (new);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**new;

	if (!str || !c)
		return (0);
	new = malloc(sizeof(char*) * (count(str, c)));
	if (!new)
		return (0);
	return (norm(str, new, c));
}
