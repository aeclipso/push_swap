//
// Created by aeclipso on 9/5/20.
//
#include "libft.h"

int 		ft_lstsize(t_list *lst)
{
	int 	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
