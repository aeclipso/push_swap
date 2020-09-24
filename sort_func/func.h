#ifndef SORT_FUNC_H
#define SORT_FUNC_H
#include <stdlib.h>
#include "../libft/libft.h"
void		push_a(t_list **top_a, t_list **top_b);
void		push_b(t_list **top_a, t_list **top_b);
void		rotate(t_list **top, char stack);
void		r_rotate(t_list **top_a, t_list **top_b);
void		rerotate(t_list **top, char stack);
void		r_rerotate(t_list **top_a, t_list **top_b);
void		swap(t_list **top, char stack);
void		s_swap(t_list **top_a, t_list **top_b);

#endif //SORT_FUNC_H
