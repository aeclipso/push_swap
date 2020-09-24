/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whatismyint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:35:32 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/21 01:41:12 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_whatismyint(int n)
{
	int			i;

	i = 0;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
