#include "libft.hpp"

t_list	*ft_lstnew(int data)
{
	t_list	*head;

	head = new t_list;
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}