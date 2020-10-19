#include "func.h"
#include <unistd.h>

void		swap(t_list **top)
{
	t_list	*temp;
	t_list	*sec;
	
	if (!(*top) || !(*(top))->next)
		return ;
	temp = *top;
	*top = (*(top))->next;
	sec = (*(top))->next;
	(*(top))->next = temp;
	temp->next = sec;
}

void		s_swap(t_list **top_a, t_list **top_b)
{
	swap(top_a);
	swap(top_b);
}

void		do_sa(t_list **top_a)
{
	swap(top_a);
	ft_printf("sa\n");
}

void		do_sb(t_list **top_b)
{
	swap(top_b);
	ft_printf("sb\n");
}

void		do_ss(t_list **top_a, t_list **top_b)
{
	s_swap(top_a, top_b);
	ft_printf("ss\n");
}