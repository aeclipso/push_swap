#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"
# include <stdio.h> //DEBUG
# include "../libft-printf/include/libft.h"

typedef struct		s_stacks
{
	t_list			*a_stack;
	t_list			*b_stack;
	int				min;
	int				max;
	int				length;
}					t_stacks;

typedef struct		s_elemstack
{
	int				index;
	int 			flag_index;
	int				number;
}					t_elemstack;

int				ft_core(int argc, char **argv);
void			ft_error(void);

int				ft_reading(int argc, char **argv, t_list **struct_list);

int				ft_stringtonumbers(t_list *reading_list, t_list **int_list);

char			**ft_strsplit(char const *s, char c);

int				ft_isdigitorsize(int c);
int				ft_checkstring(char *s);
int				ft_startcheck(t_list *node);
int				ft_whitespace(char *str);


size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);


int					ft_creategeneral(t_stacks *general, t_list *int_list);
void				ft_cleargeneral(t_stacks *general);
#endif //PUSH_SWAP_H