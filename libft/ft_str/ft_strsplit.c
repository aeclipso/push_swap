/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:20:34 by aeclipso          #+#    #+#             */
/*   Updated: 2020/07/08 01:02:09 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_c(char *s, char c)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static char			*ft_s(size_t size)
{
	char			*arr;
	size_t			i;

	i = 0;
	arr = (char*)malloc(size + 1);
	if (!(arr))
		return (NULL);
	while (i < size + 1)
	{
		arr[i] = 0;
		i++;
	}
	return (&arr[0]);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**r;
	char			*t;
	size_t			i[3];

	if (!s || !(r = (char**)malloc(sizeof(char*) * ft_countw(s, c) + 1)))
		return (NULL);
	t = (char*)s;
	ft_tozero3(&i[0], &i[1], &i[2]);
	while (i[1] < ft_countw(t, c))
	{
		if (!(r[i[1]] = ft_s(ft_c(&t[i[0]], c) + 1)) || ft_c(&t[i[0]], c) == 0)
		{
			while (i[1]-- > 0)
				free(r[i[1]]);
			return (NULL);
		}
		while (t[i[0]] == c)
			i[0]++;
		while (t[i[0]] != c && t[i[0]] != 0)
			r[i[1]][i[2]++] = t[i[0]++];
		i[1]++;
		i[2] = 0;
	}
	r[i[1]] = NULL;
	return (r);
}
