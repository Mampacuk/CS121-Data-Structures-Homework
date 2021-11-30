/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PQEntry.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:59:22 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 13:59:22 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PQENTRY_HPP
# define PQENTRY_HPP

# include "../../libft/IPriorityQueue.hpp"
# include "../../libft/IComparator.hpp"
# include <iostream>

template <typename K, typename V>
class	PQEntry : virtual public IPriorityQueue<K, V>::Entry
{
	public:
		PQEntry(K _k, V _v) : _k(_k), _v(_v) {}
		const K	&getKey(void)	const { return (this->_k); }
		const V	&getValue(void)	const { return (this->_v); }
	private:
		K		_k;
		V		_v;
};

static int	ft_parent(int index)
{
	return ((index - 1) / 2);
}

static int	ft_left(int index)
{
	return (index * 2 + 1);
}

static int ft_right(int index)
{
	return (index * 2 + 2);
}

template <typename K, typename V>
static void	ft_swap_pointers(typename IPriorityQueue<K, V>::Entry **arr, int a, int b)
{
	typename IPriorityQueue<K, V>::Entry	*temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

template <typename K, typename V>
bool	ft_compare(const IComparator<K> &comp, typename IPriorityQueue<K, V>::Entry *a, typename IPriorityQueue<K, V>::Entry *b)
{
	return (comp(a->getKey(), b->getKey()));
}

template <typename K, typename V>
void	ft_print_keys(typename IPriorityQueue<K, V>::Entry **arr)
{
	if (!arr || !(*arr))
	{
		std::cout << "(null)";
		return ;
	}
	std::cout << "(";
	while (*arr)
	{
		std::cout << (*arr)->getKey() << " ";
		arr++;
	}
	std::cout << ")";
}

template <typename K, typename V>
static void	ft_downheap(typename IPriorityQueue<K, V>::Entry **arr, const IComparator<K> &comp, int n, int index)
{
	while (index < n)
	{
		int	selected;
		if (ft_left(index) < n && ft_right(index) < n)
			selected = ft_compare<K, V>(comp, arr[ft_left(index)], arr[ft_right(index)])
				? ft_right(index) : ft_left(index);
		else if (ft_left(index) < n)
			selected = ft_left(index);
		else if (ft_right(index) < n)
			selected = ft_right(index);
		else
			break ;
		if (ft_compare<K, V>(comp, arr[index], arr[selected]))
		{
			ft_swap_pointers<K, V>(arr, index, selected);
			index = selected;
		}
		else
			break ;
	}
}

template <typename K, typename V>
typename IPriorityQueue<K, V>::Entry	**ft_k_max_entries(typename IPriorityQueue<K, V>::Entry **arr, const IComparator<K> &comp, int n, int k)
{
	int										i;
	typename IPriorityQueue<K, V>::Entry	**copy;
	typename IPriorityQueue<K, V>::Entry	**result;

	if (n < 1 || k < 1 || k > n || !arr || !(*arr))
		return (NULL);
	copy = new typename IPriorityQueue<K, V>::Entry *[n + 1];
	copy[n] = NULL;
	for (int j = 0; j < n; j++)
		copy[j] = arr[j];
	result = new typename IPriorityQueue<K, V>::Entry *[k + 1];
	result[k] = NULL;
	/*
	 * Bottom-up construction
	 */
	for (int j = ft_parent(n - 1); j >= 0; j--)
		ft_downheap<K, V>(copy, comp, n, j);
	/*
	 * Insertion into array, removal from the tree
	 */
	i = 0;
	while (i < k)
	{
		result[i] = *copy;
		*copy = copy[n - 1 - i];
		ft_downheap<K, V>(copy, comp, n - i, 0);
		i++;
	}
	delete [] copy;
	return (result);
}


#endif
