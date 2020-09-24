//
// Created by aeclipso on 9/5/20.
//

#include "libft.h"

void 		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*temp;
	
	temp = *lst;
	if (lst)
	{
		if(*lst)
		{
			while ((*lst)->next)
				(*lst)=(*lst)->next;
			(*lst)->next = new;
		}
	}
	*lst = temp;
}