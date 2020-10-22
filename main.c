/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 03:13:47 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/20 18:52:20 by aeclipso         ###   ########.fr       */
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

static void			ft_lstdebugcircle(t_stacks *general)
{
	t_list			*a = general->a_stack;
	t_list			*b = general->b_stack;
	
	while (a)
	{
		printf("III\t%i\n", ((t_elemstack *)(a->content))->number);
		a = a->next;
	}

	while (b)
	{
		printf("IIB\t%i\n", ((t_elemstack *)(b->content))->number);
		b = b->next;
	}
	
	
}

static void			ft_lstdebugprint(t_list *i)
{
	while (i)
	{
		ft_printf("DP m\t%s\n", ((char *)(i->content)));
		i = i->next;
	}
}

static void			ft_lstdebugprintint(t_list *i)
{
	while (i)
	{
		ft_printf("INT\t%i\n", ((int *)(i->content))[0]);
		i = i->next;
	}
}

int					ft_core(int argc, char **argv)
{
	t_list			*reading_list;
	t_list			*int_list;
	t_stacks		general;

	if (!(ft_reading(argc, argv, &reading_list)))
	{
		ft_lstclear(&reading_list, free);
		ft_error();
	}
 	ft_lstdebugprint(reading_list);
	ft_stringtonumbers(reading_list, &int_list);
	ft_creategeneral(&general, int_list);

	ft_zeroflags(&(general.a_stack));
	ft_markup(&(general.a_stack));
	
	main_solver(&general);
	ft_lstdebugcircle(&general);
	// ft_cleargeneral(&general);
	// ft_lstclear(&reading_list, free);
	// ft_lstdebugprintint(int_list);
	// ft_lstclear(&int_list, free);
	return(1);
}

void				ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
