#include "sorting.hpp"

// char	**ft_smallest_string(char **arr)
// {
// 	// char	*curr;
// 	// char	**smallest;

// 	// curr = *arr;
// 	// while (++arr)
// 	// {
// 	// 	if (ft_strcmp(*arr, curr) < 0)
// 	// 		smallest = arr;
// 	// }
// 	// return (smallest);
// }

char	*ft_smallest_string(char **arr, char *smallest)
{
	if (!arr)
		return (smallest);
	if (ft_strcmp(*arr, smallest) < 0)
		smallest = *arr;
	return (ft_smallest_string(arr + 1, smallest));
}

// void	ft_selection_sort(char **arr)
// {
// 	//
// }