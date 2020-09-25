/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 03:47:27 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/25 17:22:04 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int						ft_isdigitorsize(int c)
{
	if ((c >= 48 && c <= 57) || c == '+' || c == '-' || c ==' ')
		return (1);
	return (0);
}

int 					ft_checkstring(char *s)
{
	size_t				i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigitorsize(s[i])))
			return (0);
		i++;
	}
	return (1);
}

// int					ft_startcheck(t_list *node)
// {
// 	while (node)
// 	{
// 		if(!(ft_checkstring((char *)(node->content))))
// 			return (0);
// 		node = node->next;
// 	}
// 	return (1);
// }

int					ft_whitespace(char *str)
{
	size_t			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}