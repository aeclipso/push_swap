/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:39:05 by aeclipso          #+#    #+#             */
/*   Updated: 2019/09/17 13:38:18 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	int				sign;
	long long int	nbr;

	sign = 1;
	nbr = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
			|| *nptr == '\f' || *nptr == '\r' || *nptr == '\n')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (ft_longover(nptr, sign) == 1)
	{
		while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
		{
			nbr = nbr * 10 + (*nptr - '0');
			nptr++;
		}
		return ((int)nbr * sign);
	}
	else
		return (ft_longover(nptr, sign));
}
