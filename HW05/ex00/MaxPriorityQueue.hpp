/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaxPriorityQueue.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:33:55 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 14:33:55 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAXPRIORITYQUEUE_HPP
# define MAXPRIORITYQUEUE_HPP

# include "../../libft/SortedPriorityQueue.hpp"
# include "../../libft/ArrayVector.hpp"

template <typename V>
class	MaxPriorityQueue
{
	private:
		SortedPriorityQueue<int, V>				_pq;
	public:
		typename IPriorityQueue<int, V>::Entry	*max(void);
		void									insert(int key, const V &value);
		void									removeMax(void);
		int										size(void)	const;
		bool									empty(void)	const;
		void									print(void)	const;
};

template <typename V>
void	MaxPriorityQueue<V>::insert(int key, const V &value)
{
	this->_pq.insert(key, value);
}

template <typename V>
void	MaxPriorityQueue<V>::removeMax(void)
{
	if (this->_pq.empty())
		return ;

	ArrayVector<typename IPriorityQueue<int, V>::Entry*>	entries;
	while (this->_pq.size() != 1)
	{
		entries.insert(entries.size(), this->_pq.min());
		this->_pq.removeMin();
	}
	this->_pq.removeMin();
	while (!entries.empty())
	{
		this->_pq.insert((entries[entries.size() - 1])->getKey(), (entries[entries.size() - 1])->getValue());
		entries.erase(entries.size() - 1);
	}
}

template <typename V>
typename IPriorityQueue<int, V>::Entry	*MaxPriorityQueue<V>::max(void)
{
	if (this->_pq.empty())
		return (NULL);

	typename IPriorityQueue<int, V>::Entry					*ret;
	ArrayVector<typename IPriorityQueue<int, V>::Entry*>	entries;
	while (this->_pq.size() != 1)
	{
		entries.insert(entries.size(), this->_pq.min());
		this->_pq.removeMin();
	}
	ret = this->_pq.min();
	while (!entries.empty())
	{
		this->_pq.insert((entries[entries.size() - 1])->getKey(), (entries[entries.size() - 1])->getValue());
		entries.erase(entries.size() - 1);
	}
	return (ret);
}

template <typename V>
bool	MaxPriorityQueue<V>::empty(void) const
{
	return (this->_pq.empty());
}

template <typename V>
int	MaxPriorityQueue<V>::size(void) const
{
	return (this->_pq.size());
}

template <typename V>
void	MaxPriorityQueue<V>::print(void) const
{
	this->_pq.print();
}

#endif
