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

void		do_push_a(t_list **top_a, t_list **top_b)
{
	push_a(top_a, top_b);
	ft_printf("pa\n");
}

void		do_push_b(t_list **top_a, t_list **top_b)
{
	push_b(top_a, top_b);
	ft_printf("pb\n");
}
