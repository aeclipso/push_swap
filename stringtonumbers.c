/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringtonumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:22:53 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/30 10:40:34 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int					ft_isdigit(int c)					//TODO: удалить, т.к. есть в либе
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int					*ft_createoneint(int value)
{
	int				*value_temp;

	if (!(value_temp = (int *)malloc(sizeof(int))))
		return (NULL);
	((int*)(value_temp))[0] = value;
	return (value_temp);
}

int					ft_checkduplicate(t_list **int_list)
{
	t_list			*a;
	t_list			*b;

	a = *int_list;
	b = (*int_list)->next;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (((int *)(a->content))[0] == ((int *)(b->content))[0])
				ft_error();
			b = b->next;
		}
		a = a->next;
	}
}
/*
** TODO: сделать валидацию на инты, чтобы ни больше, ни меньше
** TODO: валидация на невалидные аргументы, почему то руинится, если передать строку с буквами
** TODO: АТОИ
*/

int			ft_stringtonumbers(t_list *reading_list, t_list **int_list)
{
	int *value;

	*int_list = ft_lstnew(ft_createoneint(ft_atoi((char*)reading_list->content)));		//TODO: verylong string FIX
	reading_list = reading_list->next;
	while (reading_list)
	{
		ft_lstadd_back(int_list, ft_lstnew(ft_createoneint(ft_atoi((char*)reading_list->content)))); //TODO: verylong string FIX
		reading_list = reading_list->next;
	}
	ft_checkduplicate(int_list);
//	ft_lstdebugprintint(int_list);
	return (1);
}
