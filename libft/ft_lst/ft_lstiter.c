//
// Created by aeclipso on 9/5/20.
//

#include "libft.h"

void 		ft_lstiter(t_list *lst, void (*f)(void *))
{
	if(!lst || !f)
		return ;
	if(lst->next)
		ft_lstiter(lst->next, f);
	f(lst->content);
}