#include "func.h"
#include <unistd.h>

void		rerotate(t_list **top, char stack)
{
	t_list	*temp;
	t_list	*sec;
	
	char	r = 'r';
	char 	n = '\n';
	
	temp = *top;
	sec = ft_beforelast(*top);
	*top =ft_lstlast(*top);
	(*(top))->next = temp;
	sec->next = NULL;
	
	if (stack == 'a' || stack == 'b')
	{
		write(1, &r, 1);
		write(1, &r, 1);
		write(1, &stack, 1);
		write(1, &n, 1);
	}
}

void		r_rerotate(t_list **top_a, t_list **top_b)
{
	char	r = 'r';
	char	n = '\n';
	
	rerotate(top_a, 'r');
	rerotate(top_b, 'r');
	
	write(1, &r, 1);
	write(1, &r, 1);
	write(1, &r, 1);
	write(1, &n, 1);
}