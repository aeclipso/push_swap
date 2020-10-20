#include "func.h"
#include <unistd.h>

void		rerotate(t_list **top)
{
	t_list	*temp;
	t_list	*sec;

	temp = *top;
	sec = ft_beforelast(*top);
	*top =ft_lstlast(*top);
	(*(top))->next = temp;
	sec->next = NULL;
}

void		r_rerotate(t_list **top_a, t_list **top_b)
{
	rerotate(top_a);
	rerotate(top_b);
}

void		do_rra(t_list **top_a)
{
	rerotate(top_a);
	ft_printf("rra\n");
}

void		do_rrb(t_list **top_b)
{
	rerotate(top_b);
	ft_printf("rrb\n");
}

void		do_rrr(t_list **top_a, t_list **top_b)
{
	r_rerotate(top_a, top_b);
	ft_printf("rrr\n");
}