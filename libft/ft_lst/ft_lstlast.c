//
// Created by aeclipso on 9/5/20.
//

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst=lst->next;
	return (lst);
}

t_list		*ft_beforelast(t_list *lst)
{
	while (lst->next->next)
		lst=lst->next;
	return (lst);
}