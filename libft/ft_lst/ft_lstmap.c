//
// Created by aeclipso on 9/5/20.
//

#include "libft.h"

t_list 		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if(!lst || !f || !del)
		return (NULL);
	while (lst->next)
	{
		if(!(new = ft_lstnew(f(lst->content))))
			return (NULL);
		temp = lst->next;
		del(lst);
		lst = temp;
		new->next = NULL;
	}

}
