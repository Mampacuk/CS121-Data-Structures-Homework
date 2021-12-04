/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISortedMap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:01:57 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/05 00:01:57 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISORTEDMAP_HPP
# define ISORTEDMAP_HPP

# include "IMap.hpp"
# include "ArrayVector.hpp"

template <typename K, typename V>
class	ISortedMap : virtual IMap<K, V>
{
	public:
		virtual typename IMap<K, V>::Entry	*firstEntry()	const = 0;
		virtual typename IMap<K, V>::Entry	*lastEntry()	const = 0;
		virtual typename IMap<K, V>::Entry	*ceilingEntry(const K&) const = 0;
		virtual typename IMap<K, V>::Entry	*floorEntry(const K&) const = 0;
		virtual typename IMap<K, V>::Entry	*lowerEntry(const K&) const = 0;
		virtual typename IMap<K, V>::Entry	*higherEntry(const K&) const = 0;
		virtual ArrayVector<typename IMap<K, V>::Entry*> submap(const K &k1, const K &k2) const = 0;
};

#endif
