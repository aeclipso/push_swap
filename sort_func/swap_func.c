#include "func.h"
#include <unistd.h>

void		swap(t_list **top)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*head;

	first = *top;
	second = first->next;
	if (!first || !second)
		return ;
	third = second->next;
	head = second;
	if (!third)
		first->next = NULL;
	else
		first->next = third;
	second->next = first;
	*top = head;
	
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


void		s_swap(t_list **top_a, t_list **top_b)
{
	swap(top_a);
	swap(top_b);
}

void		do_ss(t_list **top_a, t_list **top_b)			//NEED TEST
{
	s_swap(top_a, top_b);
	ft_printf("ss\n");
}
