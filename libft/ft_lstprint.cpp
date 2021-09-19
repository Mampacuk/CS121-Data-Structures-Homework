#include "libft.hpp"

void	ft_lstprint(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}