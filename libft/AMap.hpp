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
	protected:
		IComparator<K>	*_comp;
		class	DefaultComparator : public IComparator<K>
		{
			public:
				bool	operator()(const K &x, const K &y) const
				{
					if (std::max(x, y) == y)
						return (true);
					return (false);
				}
		};
		AMap() : _comp(new DefaultComparator) {}
		explicit AMap(IComparator<K> *_comp) : _comp(_comp) {}
		class MapEntry : public IMap<K, V>::Entry
		{
			public:
				MapEntry(K _k, V _v) : _k(_k), _v(_v) {}
				const K		&getKey() const { return (this->_k); }
				const V		&getValue() const { return (this->_v); }
				void	setValue(const V &_v) { this->_v = _v; }
				void	setKey(const K &_k) { this->_k = _k; }
			private:
				K		_k;
				V		_v;
		};
		bool	equals(const K &a, const K &b) const
		{
			return (this->_comp->operator()(a, b) && this->_comp->operator()(b, a));
		}
	public:
		List<K>	keys() const
		{
			List<K>	keys;
			List<typename IMap<K, V>::Entry*>	entries = this->entries();
			for (auto it = entries.begin(); it != entries.end(); ++it)
				keys.insertBack((*it)->getKey());
			return (keys);
		}
		List<V>	values() const
		{
			List<V>	vals;
			List<typename IMap<K, V>::Entry*>	entries = this->entries();
			for (auto it = entries.begin(); it != entries.end(); ++it)
				vals.insertBack((*it)->getValue());
			return (vals);
		}
		bool	empty() const { return (!this->size()); }
		virtual ~AMap() {}
};

#endif
