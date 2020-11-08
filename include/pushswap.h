#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"
# include <stdio.h> //DEBUG
# include "../libft-printf/include/libft.h"
# define GIANT 500
# define BIG 100
# define FIVE 5
# define THREE 3
# define A a_stack
# define B b_stack
# define G general
# define FORVARD_B 100
# define BACK_B 200
/*
 * length надо сделать так, чтобы при пушинге стеков, в одном уменьшалось,
 * а в другом увеличивалось
 */
typedef struct		s_stacks
{
	t_list			*a_stack;
	t_list			*b_stack;
	int				min;
	int				max;
	size_t			length_a;
	size_t			length_b;
	size_t			start_len;
}					t_stacks;

typedef struct		s_elemstack
{
	size_t			index;
	int 			flag_index;
	int				number;
}					t_elemstack;

int					ft_core(int argc, char **argv);
void				ft_error(void);

int					ft_reading(int argc, char **argv, t_list **struct_list);

int					ft_stringtonumbers(t_list *reading_list, t_list **int_list);

char				**ft_strsplit(char const *s, char c);

int					ft_isdigitorsize(int c);
int					ft_checkstring(char *s);
int					ft_startcheck(t_list *node);
int					ft_whitespace(char *str);

int					ft_creategeneral(t_stacks *general, t_list *int_list);
void				ft_cleargeneral(t_stacks *general);

void				ft_zeroflags(t_list **stack_a);
void				ft_markup(t_list **stack_a);

int					is_sort(t_list **stack);
int					is_revsort(t_list **stack);

int					main_solver(t_stacks *general);

/*
**	sorts
*/
void				five_sort(t_stacks *general);
void				three_sort(t_stacks *general);
void				two_sort(t_stacks *general);

#endif //PUSH_SWAP_H