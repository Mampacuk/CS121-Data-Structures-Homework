#include "sorting.hpp"

static void	ft_insert_element(char **arr, char **head)
{
	if (!arr || !(*arr) || !head || !(*head) || arr == head)
		return ;
	if (ft_strcmp(*(arr - 1), *arr) > 0)
		ft_swap(arr, arr - 1);
	else
		return ;
	ft_insert_element(arr - 1, head);
}

void	ft_insertion_sort(char **arr, char **head)
{
	if (!arr || !(*arr) || !head || !(*head))
		return ;
	ft_insert_element(arr, head);
	ft_insertion_sort(arr + 1, head);
}
