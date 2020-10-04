#include "func.h"

void		push_a(t_list **top_a, t_list **top_b)
{
	t_list	*temp;
	
	if (*top_a && *top_b)
		temp = (*(top_b))->next;
	if (!(*top_b))
		return ;
	(*(top_b))->next = *top_a;
	*top_a = *top_b;
	*top_b = temp;
}

void		push_b(t_list **top_a, t_list **top_b)
{
	t_list	*temp;

	if (*top_a && *top_b)
		temp = (*(top_a))->next;
	if (!(*top_a))
		return ;
	(*(top_a))->next = *top_b;
	*top_b = *top_a;
	*top_a = temp;
}

//TODO: придумать, как будут выводиться команды