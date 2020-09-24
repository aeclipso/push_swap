/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:53:57 by aeclipso          #+#    #+#             */
/*   Updated: 2020/07/08 01:00:07 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t				ft_strlen(const char *str)
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
