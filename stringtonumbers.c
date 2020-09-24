//
// Created by aeclipso on 9/9/20.
//

#include "pushswap.h"
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int					ft_atoi(const char *nptr)
{
	size_t			nbr;
	int				sign;
	
	sign = 1;
	nbr = 0;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr)
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == -1 && nbr > 2147483648)
		return (0);
	else if (sign == 1 && nbr > 2147483647)
		return (-1);
	else
		return (sign * (int)nbr);
}

int			*ft_createoneint(int value)
{
	int		*value_temp;
	
	if (!(value_temp = (int *)malloc(sizeof(int))))
		return (NULL);
	((int*)(value_temp))[0] = value;
	return (value_temp);
}


static void			ft_lstdebugprintint(t_list *i)
{
	while (i)
	{
		printf("INT\t%i\n", ((int *)(i->content))[0]);
		i = i->next;
	}
}

/*
 * TODO: сделать валидацию на инты, чтобы ни больше, ни меньше
 * TODO: валидация на невалидные аргументы, почему то руинится, если передать строку с буквами
 * TODO: АТОИ
 */

int			ft_stringtonumbers(t_list *reading_list, t_list **int_list)
{
	int *value;
	
	*int_list = ft_lstnew(ft_createoneint(ft_atoi((char*)reading_list->content)));
	reading_list = reading_list->next;
	while (reading_list)
	{
		ft_lstadd_back(int_list, ft_lstnew(ft_createoneint(ft_atoi((char*)reading_list->content))));
		reading_list = reading_list->next;
	}
//	ft_lstdebugprintint(int_list);
}