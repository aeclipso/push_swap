/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_cp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 04:04:24 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/06 04:04:42 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char*)str;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t			i;
	char			*arr;

	i = ft_strlen(s);
	if (!(arr = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
