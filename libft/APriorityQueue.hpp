/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APriorityQueue.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:08:08 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/24 15:08:08 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APRIORITYQUEUE_HPP
# define APRIORITYQUEUE_HPP

# include "IPriorityQueue.hpp"
# include "IComparator.hpp"
# include <algorithm>

template <typename K, typename V>
class	APriorityQueue : public IPriorityQueue<K, V>
{
	private:
		IComparator<K>	*_comp;
	protected:
		class	DefaultComparator : public IComparator<K>
		{
			public:
				bool	operator()(const K &x, const K &y) const
				{
					const K	&maximum = std::max(x, y);
					if (maximum == y)
						return (true);
					return (false);
				}
		};
		APriorityQueue(void) : _comp(new DefaultComparator()) {}
		explicit APriorityQueue(IComparator<K> *comparator) : _comp(comparator) {}
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
		bool	compare(const typename IPriorityQueue<K, V>::Entry &a, const typename IPriorityQueue<K, V>::Entry &b) const
		{
			return (this->_comp->operator()(a.getKey(), b.getKey()));
		}
	public:
		bool	empty(void)	const { return (!this->size()); }
		virtual	~APriorityQueue(void) {}
};

#endif
