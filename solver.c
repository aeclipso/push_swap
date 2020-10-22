/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:02:31 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/21 21:16:38 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include "sort_func/func.h"

static void		extra_big_sort(t_stacks *general)
{
	ft_printf("EXTRA BIG SORT\n");
}

static void		big_sort(t_stacks *general)
{
	ft_printf("BIG SORT\n");
}



	/* TESTING
	t_list		*shufle_a = general->a_stack;
	t_list		*shufle_b = general->b_stack;

	while (shufle_a)
	{
		ft_printf("ST_A:\n%i\n", ((t_elemstack *)(shufle_a->content))->number);
		shufle_a = shufle_a->next;
	}
	while (shufle_b)
	{
		ft_printf("ST_B:\n%i\n", ((t_elemstack *)(shufle_b->content))->number);
		ft_printf("LEN_B:\t%i\n", general->length_b);
		shufle_b = shufle_b->next;
	}
	*/

static int		f_analitic_sort(t_stacks *general)
{
	if (is_sort(&general->a_stack))
		return (1000);
	if (general->length_a == 2)
		two_sort(general);
	else if (general->length_a == 3)
		three_sort(general);
	else if (general->length_a < 6)
		five_sort(general);
	else if (general->length_a < 100)
		big_sort(general);
	else 
		extra_big_sort(general);
}


int				main_solver(t_stacks *general)
{
	f_analitic_sort(general);
}