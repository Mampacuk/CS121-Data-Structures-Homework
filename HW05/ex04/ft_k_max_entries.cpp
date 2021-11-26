/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_k_max_entries.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:58:23 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 15:58:23 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ArrayVector.hpp"
#include "../../libft/IPriorityQueue.hpp"
#include "../../libft/IComparator.hpp"

void	ft_print_keys(ArrayVector<IPriorityQueue<char, char>::Entry*> &vector);

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

static void	ft_swap_pointers(ArrayVector<IPriorityQueue<char, char>::Entry*> &vector, int a, int b)
{
	IPriorityQueue<char, char>::Entry	*temp = vector[a];
	vector[a] = vector[b];
	vector[b] = temp;
}

template <typename K, typename V>
void	ft_k_max_entries(IPriorityQueue<K, V>::Entry *arr, const IComparator<K> &comp, int n, int k)
{
	int	i;
	int j;

	if (vector.size() < 2)
		return ;
	/*
	 * Forming a max heap by performing upheaps
	 */
	i = 1;
	while (i < vector.size())
	{
		j = i;
		while (j && vector[ft_parent(j)]->getKey() < vector[j]->getKey())
		{
			ft_swap_pointers(vector, j, ft_parent(j));
			j = ft_parent(j);
		}
		i++;
	}
	/*
	 * Sorting from the end by performing downheaps
	 */
	i = vector.size() - 1;
	while (i > 0)
	{
		j = 0;
		ft_swap_pointers(vector, j, i);
		while (j < i)
		{
			int	selected;
			if (ft_left(j) < i && ft_right(j) < i)
				selected = vector[ft_left(j)]->getKey() > vector[ft_right(j)]->getKey() ? ft_left(j) : ft_right(j);
			else if (ft_left(j) < i)
				selected = ft_left(j);
			else if (ft_right(j) < i)
				selected = ft_right(j);
			else
				break ;
			if (vector[j]->getKey() < vector[selected]->getKey())
			{
				ft_swap_pointers(vector, j, selected);
				j = selected;
			}
			else
				break ;
		}
		i--;
	}
}
