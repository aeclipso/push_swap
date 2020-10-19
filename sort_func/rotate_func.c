#include "func.h"
#include <unistd.h>

void		rotate(t_list **top)
{
	t_list	*temp;
	t_list	*sec;

	sec = (*(top))->next;
	temp = *top;
	*top = ft_lstlast(*top);
	(*(top))->next = temp;
	temp->next = NULL;
	*top = sec;
}

void		r_rotate(t_list **top_a, t_list **top_b)
{
	rotate(top_a);
	rotate(top_b);
}

void		do_ra(t_list **top_a)
{
	rotate(top_a);
	ft_printf("ra\n");
}

void		do_rb(t_list **top_b)
{
	rotate(top_b);
	ft_printf("rb\n");
}

void		do_rr(t_list **top_a, t_list **top_b)
{
	r_rotate(top_a, top_b);
	printf("rr\n");
}