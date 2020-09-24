//
// Created by aeclipso on 9/5/20.
//

#include "libft.h"

void 		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp;
	
	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
}