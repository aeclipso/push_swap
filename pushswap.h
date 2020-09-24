#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h> //DEBUG

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


int					ft_atoi(const char *nptr);
#endif //PUSH_SWAP_H