/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnsortedPriorityQueue.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:26:55 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/24 15:26:55 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSORTEDPRIORITYQUEUE_HPP
# define UNSORTEDPRIORITYQUEUE_HPP

# include "APriorityQueue.hpp"
# include "List.hpp"

template <typename K, typename V>
class	UnsortedPriorityQueue : virtual public APriorityQueue<K, V>
{
	private:
		List<typename IPriorityQueue<K, V>::Entry*>	_list;
		typename List<typename IPriorityQueue<K, V>::Entry*>::Iterator
			findMin(void) const;
	public:
		UnsortedPriorityQueue(void) : APriorityQueue<K, V>() {}
		~UnsortedPriorityQueue(void) {}
		explicit UnsortedPriorityQueue(IComparator<K> *comparator) : APriorityQueue<K, V>(comparator) {}
		typename IPriorityQueue<K, V>::Entry	*min(void)	const;
		void									insert(const K &key, const V &value);
		void									removeMin(void);
		int										size(void)	const;
		void									print(void)	const;
};

template <typename K, typename V>
typename List<typename IPriorityQueue<K, V>::Entry*>::Iterator	UnsortedPriorityQueue<K, V>::findMin(void) const
{
	typename List<typename IPriorityQueue<K, V>::Entry*>::Iterator	small = this->_list.begin();
	for (typename List<typename IPriorityQueue<K, V>::Entry*>::Iterator it = this->_list.begin();
		it != this->_list.end();
		++it)
		if (this->compare(**it, **small))
			small = it;
	return (small);
}

template <typename K, typename V>
typename IPriorityQueue<K, V>::Entry	*UnsortedPriorityQueue<K, V>::min(void) const
{
	if (this->_list.empty())
		return (NULL);
	return (*this->findMin());
}

template <typename K, typename V>
void	UnsortedPriorityQueue<K, V>::insert(const K &key, const V &value)
{
	this->_list.insertBack(new typename APriorityQueue<K, V>::PQEntry(key, value));
}

template <typename K, typename V>
void	UnsortedPriorityQueue<K, V>::removeMin(void)
{
	if (this->_list.empty())
		return ;
	this->_list.erase(this->findMin());
}

template <typename K, typename V>
int	UnsortedPriorityQueue<K, V>::size(void) const
{
	return (this->_list.size());
}

template <typename K, typename V>
void	UnsortedPriorityQueue<K, V>::print(void) const
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
