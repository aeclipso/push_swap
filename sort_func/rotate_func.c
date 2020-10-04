#include "func.h"
#include <unistd.h>

void		rotate(t_list **top, char stack)
{
	t_list	*temp;
	t_list	*sec;
	char	r = 'r';
	char 	n = '\n';
	
	sec = (*(top))->next;
	temp = *top;
	*top = ft_lstlast(*top);
	(*(top))->next = temp;
	temp->next = NULL;
	*top = sec;
	if (stack == 'a' || stack == 'b')
	{
		write(1, &r, 1);
		write(1, &stack, 1);
		write(1, &n, 1);
	}
}

void		r_rotate(t_list **top_a, t_list **top_b)
{
	char	r = 'r';
	char	n = '\n';
	
	rotate(top_a, 'r');
	rotate(top_b, 'r');
	
	write(1, &r, 1);
	write(1, &r, 1);
	write(1, &n, 1);
}