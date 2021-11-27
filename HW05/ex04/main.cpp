/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:32 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 13:51:32 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "PQEntry.hpp"
#include "DefaultComparator.hpp"

template <typename K, typename V>
typename IPriorityQueue<K, V>::Entry	**ft_k_max_entries(typename IPriorityQueue<K, V>::Entry **arr, const IComparator<K> &comp, int n, int k);

static typename IPriorityQueue<int, int>::Entry	**ft_generate_arr(int size)
{
	typename IPriorityQueue<int, int>::Entry	**arr;

	arr = new IPriorityQueue<int, int>::Entry *[size + 1];
	arr[size] = NULL;
	for (int i = 0; i < size; i++)
		arr[i] = new PQEntry<int, int>(rand() % 100 - 50, 0);
	return (arr);
}

static void	ft_free_memory(IPriorityQueue<int, int>::Entry **arr)
{
	IPriorityQueue<int, int>::Entry	**ptr = arr;
	if (!ptr)
		return ;
	while (*ptr)
	{
		delete *ptr;
		ptr++;
	}
	delete [] arr;
}

int	main(void)
{
	srand(time(0));
	for (int i = 1; i <= 10; i++)
	{
		IPriorityQueue<int, int>::Entry **arr = ft_generate_arr(i);
		std::cout << "The arr generated: ";
		ft_print_keys<int, int>(arr);
		for (int j = 1; j <= i; j++)
		{
			IPriorityQueue<int, int>::Entry **subarr = ft_k_max_entries<int, int>(arr, DefaultComparator<int>(), i, j);
			std::cout << std::endl << "Printing subarray with length " << j << ": ";
			ft_print_keys<int, int>(subarr);
			delete [] subarr;
		}
		ft_free_memory(arr);
		std::cout << std::endl << std::endl;
	}
}