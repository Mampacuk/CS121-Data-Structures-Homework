/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeapPriorityQueue.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:27:05 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 19:27:05 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPPRIORITYQUEUE_HPP
# define HEAPPRIORITYQUEUE_HPP

# include "APriorityQueue.hpp"
# include "ArrayVector.hpp"

template <typename K, typename V>
class	HeapPriorityQueue : public APriorityQueue<K, V>
{
	private:
		ArrayVector<typename IPriorityQueue<K, V>::Entry*>	_heap;
		void									upheap(int index);
		void									downheap(int index);
		void									swap_pointers(int a, int b);
		int										left(int index)		const;
		int										right(int index)	const;
		int										parent(int index)	const;
	public:
		HeapPriorityQueue(void) : APriorityQueue<K, V>() {}
		~HeapPriorityQueue(void) {}
		explicit HeapPriorityQueue(IComparator<K> *comparator) : APriorityQueue<K, V>(comparator) {}
		typename IPriorityQueue<K, V>::Entry	*min(void)	const;
		void									insert(const K &key, const V &value);
		void									removeMin(void);
		int										size(void)	const;
		void									print(void)	const;
};

template <typename K, typename V>
int	HeapPriorityQueue<K, V>::parent(int index) const
{
	return ((index - 1) / 2);
}

template <typename K, typename V>
int	HeapPriorityQueue<K, V>::left(int index) const
{
	return (index * 2 + 1);
}

template <typename K, typename V>
int HeapPriorityQueue<K, V>::right(int index) const
{
	return (index * 2 + 2);
}

template <typename K, typename V>
void	HeapPriorityQueue<K, V>::swap_pointers(int a, int b)
{
	typename IPriorityQueue<K, V>::Entry	*temp = this->_heap[a];
	this->_heap[a] = this->_heap[b];
	this->_heap[b] = temp;
}

template <typename K, typename V>
typename IPriorityQueue<K, V>::Entry	*HeapPriorityQueue<K, V>::min(void) const
{
	if (this->_heap.empty())
		return (NULL);
	return (this->_heap[0]);
}

template <typename K, typename V>
void	HeapPriorityQueue<K, V>::upheap(int index)
{
	while (index && this->compare(*this->_heap[index], *this->_heap[this->parent(index)]))
	{
		this->swap_pointers(index, this->parent(index));
		index = this->parent(index);
	}
}

template <typename K, typename V>
void	HeapPriorityQueue<K, V>::downheap(int index)
{
	int	i = this->_heap.size();
	while (index < i)
	{
		int	selected;
		if (this->left(index) < i && this->right(index) < i)
			selected = this->compare(*this->_heap[this->right(index)], *this->_heap[this->left(index)])
				? this->right(index) : this->left(index);
		else if (this->left(index) < i)
			selected = this->left(index);
		else if (this->right(index) < i)
			selected = this->right(index);
		else
			break ;
		if (this->compare(*this->_heap[selected], *this->_heap[index]))
		{
			this->swap_pointers(index, selected);
			index = selected;
		}
		else
			break ;
	}
}

template <typename K, typename V>
void	HeapPriorityQueue<K, V>::insert(const K &key, const V &value)
{
	this->_heap.insert(this->_heap.size(), new typename APriorityQueue<K, V>::PQEntry(key, value));
	this->upheap(this->_heap.size() - 1);
}

template <typename K, typename V>
void	HeapPriorityQueue<K, V>::removeMin(void)
{
	if (this->_heap.empty())
		return ;
	this->_heap[0] = this->_heap[this->_heap.size() - 1];
	this->_heap.erase(this->_heap.size() - 1);
	this->downheap(0);
}

template <typename K, typename V>
int	HeapPriorityQueue<K, V>::size(void) const
{
	return (this->_heap.size());
}

template <typename K, typename V>
void	HeapPriorityQueue<K, V>::print(void) const
{
	if (!this->empty())
		for (typename ArrayVector<typename IPriorityQueue<K, V>::Entry*>::Iterator it = this->_heap.begin();
			it != this->_heap.end();
			++it)
			std::cout << "key:" << (*it)->getKey() << "\tval:" << (*it)->getValue() << std::endl;
	else
		std::cout << "(null)" << std::endl;
}

#endif
