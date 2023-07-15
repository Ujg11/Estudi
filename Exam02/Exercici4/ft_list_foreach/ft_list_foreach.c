#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *l;

	l = begin_list;
	while (l != 0)
	{
		(*f)(l->data);
		l = l->next;
	}
}