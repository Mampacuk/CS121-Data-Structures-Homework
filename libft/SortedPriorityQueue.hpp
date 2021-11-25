/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortedPriorityQueue.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:14:10 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 14:14:10 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTEDPRIORITYQUEUE_HPP
# define SORTEDPRIORITYQUEUE_HPP

# include "APriorityQueue.hpp"
# include "List.hpp"

template <typename K, typename V>
class	SortedPriorityQueue : virtual public APriorityQueue<K, V>
{
	private:
		List<typename IPriorityQueue<K, V>::Entry*>	_list;
	public:
		SortedPriorityQueue(void) : APriorityQueue<K, V>() {}
		~SortedPriorityQueue(void) {}
		explicit SortedPriorityQueue(IComparator<K> *comparator) : APriorityQueue<K, V>(comparator) {}
		typename IPriorityQueue<K, V>::Entry	*min(void)	const;
		void									insert(const K &key, const V &value);
		void									removeMin(void);
		int										size(void)	const;
		void									print(void)	const;
};

template <typename K, typename V>
typename IPriorityQueue<K, V>::Entry	*SortedPriorityQueue<K, V>::min(void) const
{
	if (this->_list.empty())
		return (NULL);
	return (*this->_list.begin());
}

template <typename K, typename V>
void	SortedPriorityQueue<K, V>::insert(const K &key, const V &value)
{
	typename APriorityQueue<K, V>::PQEntry	*entry = new typename APriorityQueue<K, V>::PQEntry(key, value);
	typename List<typename IPriorityQueue<K, V>::Entry*>::Iterator	it = this->_list.begin();
	for ( ; it != this->_list.end(); ++it)
		if (this->compare(*entry, **it))
			break ;
	this->_list.insert(it, entry);
}

template <typename K, typename V>
void	SortedPriorityQueue<K, V>::removeMin(void)
{
	if (this->_list.empty())
		return ;
	this->_list.eraseFront();
}

template <typename K, typename V>
int	SortedPriorityQueue<K, V>::size(void) const
{
	return (this->_list.size());
}

template <typename K, typename V>
void	SortedPriorityQueue<K, V>::print(void) const
{
	if (!this->empty())
		for (typename List<typename IPriorityQueue<K, V>::Entry*>::Iterator it = this->_list.begin();
			it != this->_list.end();
			++it)
			std::cout << "key:" << (*it)->getKey() << "\tval:" << (*it)->getValue() << std::endl;
	else
		std::cout << "(null)" << std::endl;
}

#endif
