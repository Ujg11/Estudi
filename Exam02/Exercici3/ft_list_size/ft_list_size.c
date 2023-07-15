#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

int	ft_list_size(t_list *begin_list)
{
	t_list *l;
	int i;

	i = 0;
	l = begin_list->next;
	while (l != 0)
	{
		i++;
		l = l->next;
	}
	return (i);
}