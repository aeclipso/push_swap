/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:01:33 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/20 18:25:51 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				is_sort(t_list **stack)
{
	t_list		*shufle;

	shufle = *stack;
	if (!(shufle->next))
		return (1);
	while (shufle->next)
	{
		if (((t_elemstack *)(shufle->content))->index > ((t_elemstack *)(shufle->next->content))->index)
		{
			return (0);
		}
		shufle = shufle->next;
	}
	return (1);
}

int				is_revsort(t_list **stack)
{
	t_list		*shufle;

	shufle = *stack;
	if (!(shufle->next))
		return (1);
	while (shufle->next)
	{
		if (((t_elemstack *)(shufle->content))->index <
		((t_elemstack *)(shufle->next->content))->index)
		{
			return (0);
		}
		shufle = shufle->next;
	}
	return (1);
}
