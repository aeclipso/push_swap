/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 03:22:24 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/25 16:46:30 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void			ft_lstdebugprint(t_list *i)
{
	while (i)
	{
		printf("DP\t%s\n", ((char *)(i->content)));
		i = i->next;
	}
}

int				ft_separated(char *argv, t_list **shuffle)
{
	char		**arr_str;
	size_t		i;

	i = 0;
	arr_str = ft_strsplit(argv, ' ');
	if (!(*shuffle))
	{
		*shuffle = ft_lstnew(ft_strdup(arr_str[i]));
		free(arr_str[i]);
		i++;
	}
	while (arr_str[i])
	{
		ft_lstadd_back(shuffle, ft_lstnew(ft_strdup(arr_str[i])));
		free(arr_str[i]);
		i++;
	}
	free(arr_str);
	arr_str = NULL;
	return (1);
}

static int	ft_initlst(char *str, t_list **shuffle)
{
	*shuffle = NULL;

	if (!str)
		return (0);
	if (!(ft_checkstring(str)))
		return (0);
	if (ft_whitespace(str))
	{
		if (!(ft_separated(str, shuffle)))
			return (0);
	}
	else
		*shuffle = ft_lstnew(ft_strdup(str));
	return (1);
}

// static int						ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	return (0);
// }

int			ft_validateint(t_list *struct_list)
{
	int		nbr;
	int		len;
	
	while (struct_list)
	{
		len =  ft_strlen((char*)(struct_list->content));
		nbr = ft_atoi((char*)(struct_list->content));
		if (len >= 11 && nbr == 0)
			return (0);
		if (len >= 10 && nbr == -1)
			return (0);
		printf("VAL\t\t%i\n", nbr);
		if (nbr > 2147483647 && nbr < -2147483648)
			return (0);
		struct_list = struct_list->next;
	}
	return (1);
}

int			ft_reading(int argc, char **argv, t_list **struct_list)
{
	size_t		i;
	t_list		*shuffle;

	i = 2;
	if (!(ft_initlst(argv[1], &shuffle)))
		return (0);
	*struct_list = shuffle;
	while (i < argc)
	{
		if (!(ft_checkstring(argv[i])))
			return (0);
		if (ft_whitespace(argv[i]))
		{
			if (!(ft_separated(argv[i], &shuffle)))
				return (0);
		}
		else
			ft_lstadd_back(&shuffle, ft_lstnew(ft_strdup(argv[i])));
		i++;
	}
	if (!ft_validateint(shuffle))
		return (0);
	printf("MAXMINVAL\t%i\n", ft_validateint(shuffle));
//	ft_lstdebugprint(*struct_list);
	return (1);
}
