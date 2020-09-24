#include "func.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	t_list *a_ft;
	t_list *a_first;
	t_list *a_second;
	t_list *a_third;
	t_list *a_forth;
	
	a_first = (t_list*)malloc(sizeof(t_list));
	a_second = (t_list*)malloc(sizeof(t_list));
	a_third = (t_list*)malloc(sizeof(t_list));
	a_forth = (t_list*)malloc(sizeof(t_list));
	
	a_first->content = strdup("This is first string of stack A");
	a_second->content = strdup("This is second string of stack A");
	a_third->content = strdup("This is third string of stack A");
	a_forth->content = strdup("THIS IS FO4AC+N STR of stack A");
	a_ft = a_first;
	
	a_first->next = a_second;
	a_second->next = a_third;
	a_third->next = a_forth;
	a_forth->next = NULL;
	
	t_list *b_ft;
	t_list *b_first;
	t_list *b_second;
	t_list *b_third;
	
	b_first = (t_list*)malloc(sizeof(t_list));
	b_second = (t_list*)malloc(sizeof(t_list));
	b_third = (t_list*)malloc(sizeof(t_list));
	
	b_first->content = strdup("This is first string of stack B");
	b_second->content = strdup("This is second string of stack B");
	b_third->content = strdup("This is third string of stack B");
	b_ft = b_first;
	
	b_first->next = b_second;
	b_second->next = b_third;
	b_third->next = NULL;
	
	int i = 0;
	while (b_ft)
	{
		i++;
		printf("%i\tB:\t%s\n", i, (char*)b_ft->content);
		b_ft = b_ft->next;
	}
	a_ft = a_first;
	b_ft = b_first;
	i = 0;
	while (b_first)
	{
		i++;
		printf("%i\tB:\t%s\n", i, (char *)b_first->content);
		b_first = b_first->next;
	}
	b_first = b_ft;
	i = 0;
	while (a_first)
	{
		i++;
		printf("%i\tA:\t%s\n", i, (char *)a_first->content);
		a_first = a_first->next;
	}
	a_first = a_ft;
	rerotate(&a_first, 'a');
	rotate(&a_first, 'a');
	r_rerotate(&a_first, &b_first);
	swap(&a_first, 'a');
	swap(&a_first, 'a');
	s_swap(&a_first, &b_first);
	s_swap(&a_first, &b_first);
	i = 0;
	while (b_first)
	{
		i++;
		printf("%i\tB:\t%s\n", i, (char *)b_first->content);
		b_first = b_first->next;
	}
	i = 0;
	while (a_first)
	{
		i++;
		printf("%i\tA:\t%s\n", i, (char *)a_first->content);
		a_first = a_first->next;
	}
	
}