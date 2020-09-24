#include "func.h"
#include "../libft/libft.h"
#include <unistd.h>

void		swap(t_list **top, char stack)
{
	t_list	*temp;
	t_list	*sec;
	char	s = 's';
	char	n = '\n';
	
	if (!(*top) || !(*(top))->next)
		return ;
	temp = *top;
	*top = (*(top))->next;
	sec = (*(top))->next;
	(*(top))->next = temp;
	temp->next = sec;
	if (stack == 'a' || stack == 'b')
	{
		write(1, &s, 1);
		write(1, &stack, 1);
		write(1, &n, 1);
	}
}

void		s_swap(t_list **top_a, t_list **top_b)
{
	char	s = 's';
	char	n = '\n';
	
	swap(top_a, 's');
	swap(top_b, 's');
	write(1, &s, 1);
	write(1, &s, 1);
	write(1, &n, 1);
}