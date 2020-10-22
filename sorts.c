/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:56:13 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/21 21:16:53 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "sort_func/func.h"

size_t			min_ind(t_list *a)
{
	size_t		min;
	t_list		*shufle;

	shufle = a;
	min = 18446744073709551615UL;
	while (shufle)
	{
		if (((t_elemstack *)(shufle->content))->index < min)
			min = ((t_elemstack *)(shufle->content))->index;
		shufle = shufle->next;
	}
	return (min);
}

size_t			max_ind(t_list *a)
{
	size_t		max;
	t_list		*shufle;

	shufle = a;
	max = 0;
	while (shufle)
	{
		if (((t_elemstack *)(shufle->content))->index > max)
			max = ((t_elemstack *)(shufle->content))->index;
		shufle = shufle->next;
	}
	return (max);
}

void			three_sort(t_stacks *general)
{
	if (((t_elemstack *)(G->A)->content)->index == min_ind(G->A))
	{
		do_rra(&G->A);
		do_sa(&G->A);
	}
	else if(((t_elemstack *)(G->A)->content)->index == max_ind(G->A))
	{
		if (((t_elemstack *)(G->A->next)->content)->index != max_ind(G->A) &&
			((t_elemstack *)(G->A->next)->content)->index != min_ind(G->A))
		{
			do_ra(&G->A);
			do_sa(&G->A);
		}
		else
			do_ra(&G->A);
	}
	else
	{
		if (((t_elemstack *)(G->A->next)->content)->index == max_ind(G->A))
			do_rra(&G->A);
		else
			do_sa(&G->A);
	}	
}

void		two_sort(t_stacks *general)
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

void		five_sort(t_stacks *general)
{
	while (!(is_sort(&(G->A))))
	{
		while (G->length_a > 3 && !(is_sort(&(G->A))))
		{
			if (((t_elemstack *)(G->A->content))->index <= 1 && !(is_sort(&(G->A))))
				do_push_b(&(G->A), &(G->B), general);
			else
				do_ra(&(G->A));  //функция расчета куда крутить
		}
		if (!(is_sort(&(G->A))) && G->length_a == 3)
			three_sort(G);
		while (G->length_b)
		{
			if (((t_elemstack *)(G->B->content))->index + 1 == ((t_elemstack *)(G->A->content))->index)
				do_push_a(&(G->A), &(G->B), general);
			else if (G->length_b > 1)
				do_rb(&(G->B));  //функция расчета куда крутить
		}
	}
}