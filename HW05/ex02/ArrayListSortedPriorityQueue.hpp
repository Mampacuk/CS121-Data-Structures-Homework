/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayListSortedPriorityQueue.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:55:14 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 19:55:14 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYLISTSORTEDPRIORITYQUEUE_HPP
# define  ARRAYLISTSORTEDPRIORITYQUEUE_HPP

# include "../../libft/APriorityQueue.hpp"
# include "../../libft/ArrayVector.hpp"

/**
 * @brief PQ implementation with a Vector underneath. The trick is,
 * the container holds the entries in descending order, so that removal takes O(1) time.
 * 
 * @tparam K is the key type
 * @tparam V is the value type
 */
template <typename K, typename V>
class	 ArrayListSortedPriorityQueue : public APriorityQueue<K, V>
{
	private:
		ArrayVector<typename IPriorityQueue<K, V>::Entry*>	_vector;
	public:
		ArrayListSortedPriorityQueue(void) : APriorityQueue<K, V>() {}
		~ArrayListSortedPriorityQueue(void) {}
		explicit ArrayListSortedPriorityQueue(IComparator<K> *comparator) : APriorityQueue<K, V>(comparator) {}
		typename IPriorityQueue<K, V>::Entry	*min(void)	const;
		void									insert(const K &key, const V &value);
		void									removeMin(void);
		int										size(void)	const;
		void									print(void)	const;
};

template <typename K, typename V>
typename IPriorityQueue<K, V>::Entry	*ArrayListSortedPriorityQueue<K, V>::min(void) const
{
	if (this->_vector.empty())
		return (NULL);
	return (this->_vector.at(this->_vector.size() - 1));
}

template <typename K, typename V>
void	ArrayListSortedPriorityQueue<K, V>::insert(const K &key, const V &value)
{
	typename APriorityQueue<K, V>::PQEntry	*entry = new typename APriorityQueue<K, V>::PQEntry(key, value);
	int	insert_index = 0;
	for (typename ArrayVector<typename IPriorityQueue<K, V>::Entry*>::Iterator	it = this->_vector.begin();
		it != this->_vector.end();
		++it, insert_index++)
		if (!this->compare(*entry, **it))
			break ;
	this->_vector.insert(insert_index, entry);
}

template <typename K, typename V>
void	ArrayListSortedPriorityQueue<K, V>::removeMin(void)
{
	if (this->_vector.empty())
		return ;
	this->_vector.erase(this->_vector.size() - 1);
}

template <typename K, typename V>
int	ArrayListSortedPriorityQueue<K, V>::size(void) const
{
	return (this->_vector.size());
}

template <typename K, typename V>
void	ArrayListSortedPriorityQueue<K, V>::print(void) const
{
	if (!this->empty())
		for (typename ArrayVector<typename IPriorityQueue<K, V>::Entry*>::Iterator it = this->_vector.begin();
			it != this->_vector.end();
			++it)
			std::cout << "key:" << (*it)->getKey() << "\tval:" << (*it)->getValue() << std::endl;
	else
		std::cout << "(null)" << std::endl;
}

#endif
