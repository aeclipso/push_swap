/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:29:23 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/06 21:02:09 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void				ft_zeroflags(t_list **stack_a)
{
	t_list			*save;

	save = *stack_a;
	while ((*stack_a))
	{
		((t_elemstack *)((*stack_a)->content))->flag_index=0;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = save;
}

void				ft_markup(t_list **stack_a)
{
	t_list			*prev;
	t_list			*save;
	
	prev = *stack_a;
	save = *stack_a;
	if ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	while (*stack_a)
	{
		if (((t_elemstack *)(prev->content))->number > ((t_elemstack *)((*stack_a)->content))->number)
		{
			((t_elemstack *)(prev->content))->flag_index = 1;
		}
		else
		{
			break ;
		}
			*stack_a = (*stack_a)->next;
	}
	*stack_a = save;
}
