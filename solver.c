/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:02:31 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/08 08:42:15 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"
#include "sort_func/func.h"


static void			ft_lstdebugcircle(t_stacks *general)
{
	t_list			*a = general->a_stack;
	t_list			*b = general->b_stack;
	
	while (a)
	{
		printf("IIA\t%i\n", ((t_elemstack *)(a->content))->number);
		a = a->next;
	}

	while (b)
	{
		printf("IIB\t%i\n", ((t_elemstack *)(b->content))->number);
		b = b->next;
	}	
}

static void		extra_big_sort(t_stacks *general)
{
	ft_printf("EXTRA BIG SORT\n");
}

int			find_rotate(t_stacks *general)
{
	t_list	*shufle;
	t_list	*top_a;
	int		direction;
	int		result;

	shufle = general->b_stack;
	top_a = general->a_stack;
	direction = 0;
	result = 0;
	while (((t_elemstack *)(shufle->content))->index 
	!= ((t_elemstack *)(top_a->content))->index - 1)
	{
		shufle = shufle->next;
		direction++;
	}
	result = ((G->length_b) - direction);
	if (result > G->length_b / 2)
		return (FORVARD_B);
	else
		return (BACK_B);
	
	
}

void		find_next(t_stacks *general)
{
	// while (G->length_b)
	// {
		if (((t_elemstack *)(G->B->content))->index ==
		((t_elemstack *)(G->A->content))->index - 1)
			do_push_a(&(G->A), &(G->B), general);
		else if (find_rotate(general) == FORVARD_B)
			do_rb(&(G->B));
		else if (find_rotate(general) == BACK_B)
			do_rrb(&(G->B));
			
	// }
}

static void		big_sort(t_stacks *general)
{
	//TODO: изменить условия переноса в стек б, чтобы было менше операций, разметить стек а на последовательность элементов идущих
		while (G->length_a > 2 )
		{
			if(((t_elemstack *)(G->A->content))->index == 0
			|| ((t_elemstack *)(G->A->content))->index == (G->start_len - 1))
				do_ra(&(G->A));   
			else
				do_push_b(&(G->A), &(G->B), general);
		}
		while (G->start_len != G->length_a)
		{
			if (is_sort(&general->a_stack))
				do_sa(&(G->A));
			// ft_printf("LA = %i\n", G->length_a);
			// ft_printf("LB= %i\n", G->length_b);
			// ft_lstdebugcircle(general);
			find_next(general);
		}
		do_rra(&(G->A));
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
	// else if (general->length_a < 100)
	// 	big_sort(general);
	// else 
	// 	extra_big_sort(general);
	else
		big_sort(general);
	
}


int				main_solver(t_stacks *general)
{
	f_analitic_sort(general);
}