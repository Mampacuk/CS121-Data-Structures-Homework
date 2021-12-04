/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:47:48 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/02 22:47:48 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMAP_HPP
# define AMAP_HPP

# include "IMap.hpp"
# include "IComparator.hpp"
# include <algorithm>
# include <ostream>

template <typename K, typename V>
class AMap : virtual public IMap<K, V>
{
	private:
		IComparator<K>	*_equal_to;
	protected:
		class	DefaultComparator : public IComparator<K>
		{
			public:
				bool	operator()(const K &x, const K &y) const
				{
					return (x == y);
				}
		};
		AMap(void) : _equal_to(new DefaultComparator()) {}
		explicit AMap(IComparator<K> *comparator) : _equal_to(comparator) {}
		class MapEntry : public IMap<K, V>::Entry
		{
			public:
				MapEntry(K _k, V _v) : _k(_k), _v(_v) {}
				K		&getKey(void) { return (this->_k); }
				V		&getValue(void) { return (this->_v); }
				void	setValue(const V &_v) { this->_v = _v; }
				void	setKey(const K &_k) { this->_k = _k; }
			private:
				K		_k;
				V		_v;
		};
		bool	equals(const K &a, const K &b) const
		{
			return (this->_equal_to->operator()(a, b));
		}
	public:
		ArrayVector<K>	keys(void) const
		{
			ArrayVector<K>	keys;
			ArrayVector<typename IMap<K, V>::Entry*>	entries = this->entries();
			for (auto it = entries.begin(); it != entries.end(); ++it)
				keys.push_back((*it)->getKey());
			return (keys);
		}
		ArrayVector<V>	values(void) const
		{
			ArrayVector<V>	vals;
			ArrayVector<typename IMap<K, V>::Entry*>	entries = this->entries();
			for (auto it = entries.begin(); it != entries.end(); ++it)
				vals.push_back((*it)->getValue());
			return (vals);
		}
		bool	empty(void) const { return (!this->size()); }
		virtual ~AMap() {}
};

template <typename K, typename V>
std::ostream	&operator<<(std::ostream &o, const typename AMap<K, V>::MapEntry &e)
{
	o << e.getKey() << " : " << e.getValue();
	return (o);
}

#endif
