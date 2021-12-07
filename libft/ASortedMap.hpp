/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASortedMap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:13:52 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/05 00:13:52 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASORTEDMAP_HPP
# define ASORTEDMAP_HPP

# include "AMap.hpp"
# include "ISortedMap.hpp"

template <typename K, typename V>
class	ASortedMap : public ISortedMap<K, V>, public AMap<K, V>
{
	protected:
		explicit ASortedMap(IComparator<K> *comp) : AMap<K, V>::AMap(comp) {}
		ASortedMap() {}
		bool	compare(const typename IMap<K, V>::Entry *a, const typename IMap<K, V>::Entry *b) const
		{
			return (this->_comp->operator()(a->getKey(), b->getKey()));
		}
		bool	compare(const K &a, const typename IMap<K, V>::Entry *b) const
		{
			return (this->_comp->operator()(a, b->getKey()));
		}
		bool	compare(const typename IMap<K, V>::Entry *a, const K &b) const
		{
			return (this->_comp->operator()(a->getKey(), b));
		}
		bool	compare(const K &a, const K &b) const
		{
			return (this->_comp->operator()(a, b));
		}
};

#endif
