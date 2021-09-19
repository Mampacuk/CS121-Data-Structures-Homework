#include "libft.hpp"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		if (!curr->next)
			break ;
		curr = curr->next;
	}
	return (curr);
}