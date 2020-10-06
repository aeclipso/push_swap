#include "./include/pushswap.h"
#include "./libft-printf/include/libft.h"
static void	debug_print_str(t_stacks *general)
{
	printf("G-GENERAL_ind\t\t%li\n",((t_elemstack *)(general->a_stack->content))->index);
	printf("G-GENERAL_ind\t\t%li\n",((t_elemstack *)(general->a_stack->next->content))->index);
	printf("G-GENERAL_ind\t\t%li\n",((t_elemstack *)(general->a_stack->next->next->content))->index);
	printf("G-LENGEN\t%i\n", general->length_a);
	printf("G-MIN_GEN\t%i\n", general->min);
	printf("G-MAX_GEN\t%i\n", general->max);
}


static void			*ft_init_general(void *content)
{
	t_elemstack		*new;
	
	if(!(new = (t_elemstack*)malloc(sizeof(t_elemstack))))      //TODO: НЕ ЗАБЫТЬ ПОЧИСТИТЬ
		return (NULL);
	new->number=((int*)content)[0];
	new->flag_index = 0;
	return ((void *)new);
}

static int			ft_findmin(t_list *stack_a)
{
	int				min;
	t_list			*i_lst;
	
	i_lst = stack_a;
	min = ((t_elemstack *)(i_lst->content))->number;
	i_lst = i_lst->next;
	while (i_lst)
	{
		if (min > ((t_elemstack *)(i_lst->content))->number)
			min = ((t_elemstack *)(i_lst->content))->number;
		i_lst = i_lst->next;
	}
	return (min);
}

void					ft_findmin_index(t_list *stack_a, int index)
{
	int				min;
	t_list			*i_lst;
	t_list			*m_lst;

	min = 2147483647;
	m_lst = NULL;
	i_lst = stack_a;
	while (i_lst)
	{
		if (min > ((t_elemstack *)(i_lst->content))->number 
			&& ((t_elemstack *)(i_lst->content))->flag_index == 0)
		{
			min = ((t_elemstack *)(i_lst->content))->number;
			m_lst = i_lst;
		}
		i_lst = i_lst->next;
	}
	((t_elemstack *)(m_lst->content))->flag_index = 1;
	((t_elemstack *)(m_lst->content))->index = index;
}

static int			ft_findmax(t_list *stack_a)
{
	int				max;
	t_list			*i_lst;
	
	i_lst = stack_a;
	max = ((t_elemstack *)(i_lst->content))->number;
	i_lst = i_lst->next;
	while (i_lst)
	{
		if (max < ((t_elemstack *)(i_lst->content))->number)
			max = ((t_elemstack *)(i_lst->content))->number;
		i_lst = i_lst->next;
	}
	return (max);
}

static int			check_indexation(t_stacks *general)
{
	t_list			*shuffle;
	
	shuffle = general->a_stack;
	while (shuffle)
	{
		if (((t_elemstack *)(shuffle->content))->index == 0)
			return (0);
		shuffle = shuffle->next;
	}
	return (1);
}

static int			ft_checkindex(t_list *a_stack)
{
	t_list			*shuffle;
	
	shuffle = a_stack;
	while (shuffle)
	{
		if (((t_elemstack *)(shuffle->content))->flag_index == 0)
		{
			printf("HERE");
			return (0);
		}
		shuffle = shuffle->next;
	}
	return (1);
}

static int			indexation(t_stacks *general)
{
	int				i;

	i = 0;
	while (i < general->length_a)
	{
		ft_findmin_index(general->a_stack, i);
		i++;
	}
	return (1);
}

int					ft_creategeneral(t_stacks *general, t_list *int_list)
{
	general->a_stack = ft_lstmap(int_list, ft_init_general, free);
	general->length_a = ft_lstsize(general->a_stack);
	general->min = ft_findmin(general->a_stack);
	general->max = ft_findmax(general->a_stack);
	indexation(general);
	debug_print_str(general);
}

void				ft_cleargeneral(t_stacks *general)
{
	ft_lstclear(&general->a_stack, free);
}