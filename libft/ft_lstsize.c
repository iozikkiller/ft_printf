#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*next;

	res = 0;
	next = lst;
	while (next)
	{
		res++;
		next = next->next;
	}
	return (res);
}
