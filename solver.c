/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:02:31 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/20 15:00:18 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include "sort_func/func.h"
static void		extra_big_sort(t_stacks *general)
{
	ft_printf("EXTRA BIG SORT");
}

static void		big_sort(t_stacks *general)
{
	ft_printf("BIG SORT");
}

static void		five_sort(t_stacks *general)
{
	
}

static void		three_sort(t_stacks *general)
{
	if (((t_elemstack *)(general->a_stack)->content)->index == 0)
	{
		do_rra(&general->a_stack);
		do_sa(&general->a_stack);
	}
	else if(((t_elemstack *)(general->a_stack)->content)->index == 2)
	{
		if (((t_elemstack *)(general->a_stack->next)->content)->index == 1)
		{
			do_ra(&general->a_stack);
			do_sa(&general->a_stack);
		}
		else
			do_ra(&general->a_stack);
	}
	else
	{
		if (((t_elemstack *)(general->a_stack->next)->content)->index == 2)
			do_rra(&general->a_stack);
		else
			do_sa(&general->a_stack);
	}	
}

static void		two_sort(t_stacks *general)
{
	t_list		*temp;

	temp = general->a_stack;
	if (((t_elemstack *)(general->a_stack)->content)->index > 
	((t_elemstack *)(general->a_stack)->next->content)->index)
		do_sa(&temp);
	else
		return ;
	general->a_stack = temp;
}

int				is_sort(t_stacks *general)
{
	t_list		*shufle;

	shufle = general->a_stack;
	if (!(shufle->next))
		return (1);
	while (shufle->next)
	{
		if (((t_elemstack *)(shufle->content))->index >
		((t_elemstack *)(shufle->next->content))->index)
		{
			return (0);
		}
		shufle = shufle->next;
	}
	return (1);
}

static int		f_analitic_sort(t_stacks *general)
{
	if (is_sort(general))
		return (1000);
	if (general->length_a > 499)
		return (1);
	else if (general->length_a >= 100)
		return (2);
	else if (general->length_a >= 4)
		return (3);
	else if (general->length_a == 3)
		three_sort(general);
	else if (general->length_a == 2)
		two_sort(general);
	else
		return (6);
}


int				main_solver(t_stacks *general)
{
	f_analitic_sort(general);
}