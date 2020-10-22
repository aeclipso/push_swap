#ifndef SORT_FUNC_H
#define SORT_FUNC_H
#include <stdlib.h>
#include "../libft-printf/include/libft.h"
#include "pushswap.h"
void		do_push_a(t_list **top_a, t_list **top_b, t_stacks *general);
void		do_push_b(t_list **top_a, t_list **top_b, t_stacks *general);
void		do_rra(t_list **top_a);
void		do_rrb(t_list **top_b);
void		do_rrr(t_list **top_a, t_list **top_b);
void		do_ra(t_list **top_a);
void		do_rb(t_list **top_b);
void		do_rr(t_list **top_a, t_list **top_b);
void		do_sa(t_list **top_a);
void		do_sb(t_list **top_b);
void		do_ss(t_list **top_a, t_list **top_b);

#endif //SORT_FUNC_H
