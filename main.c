/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 03:13:47 by aeclipso          #+#    #+#             */
/*   Updated: 2020/09/25 16:22:12 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int					main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_core(argc, argv);
	}
}

static void			ft_lstdebugprint(t_list *i)
{
	while (i)
	{
		printf("DP m\t%s\n", ((char *)(i->content)));
		i = i->next;
	}
}

static void			ft_lstdebugprintint(t_list *i)
{
	while (i)
	{
		printf("INT\t%i\n", ((int *)(i->content))[0]);
		i = i->next;
	}
}

int					ft_core(int argc, char **argv)
{
	t_list	*reading_list;
	t_list	*int_list;

	if (!(ft_reading(argc, argv, &reading_list)))
	{
		ft_lstclear(&reading_list, free);
		ft_error();
		return (-1);
	}
 	ft_lstdebugprint(reading_list);
	ft_stringtonumbers(reading_list, &int_list);				//тут формируется стек А? или числа должны формироваться в обратном порядке
	ft_lstclear(&reading_list, free);
	ft_lstdebugprintint(int_list);
	ft_lstclear(&int_list, free);
}

void				ft_error(void)
{
	write(2, "Error\n", 6);
}

/*
*	TODO: PUSHSWAP:
*	STR_SPLIT переписать без статических переменных, окда?
*/
