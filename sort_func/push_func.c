/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:13:51 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/20 20:26:19 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"
#include "pushswap.h"

void		push_a(t_list **top_a, t_list **top_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!(*top_b))
		return ;
	if((*top_b)->next)
		head_b = (*top_b)->next;
	else
		head_b = NULL;
	head_a = *top_b;
	head_a->next = *top_a;
	*top_a = head_a;
	*top_b = head_b;
}

//TODO: проверить пуши попозже

void		push_b(t_list **top_a, t_list **top_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if ((*top_a)->next)
		head_a = (*top_a)->next;
	else
		head_a = NULL;
	head_b = *top_a;
	head_b->next = *top_b;
	*top_a = head_a;
	*top_b = head_b;
}

void		do_push_a(t_list **top_a, t_list **top_b, t_stacks *general)
{
	push_a(top_a, top_b);
	general->length_a++;
	general->length_b--;
	ft_printf("pa\n");
}

void		do_push_b(t_list **top_a, t_list **top_b, t_stacks *general)
{
	push_b(top_a, top_b);
	general->length_a--;
	general->length_b++;
	ft_printf("pb\n");
}
