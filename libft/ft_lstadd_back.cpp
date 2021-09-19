#include "libft.hpp"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = node;
		}
		else
			*lst = node;
	}
}

void	ft_lstadd_back(t_list **lst, int data)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = ft_lstnew(data);
		}
		else
			*lst = ft_lstnew(data);
	}
}