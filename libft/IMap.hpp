/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:07:45 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/02 22:07:45 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAP_HPP
# define IMAP_HPP

# include "List.hpp"
# include "IIterator.hpp"
# include <iterator>

/*
 * @brief A Map container interface. Since polymorphism is applicable
 * only to pointers and references, these methods including iterator returned
 * by value are NOT provided, and must be declared and implemented in the concrete derived class:
 * 
 * @param function Iterator	insert(const K &k, const V &v);
 * @param function Iterator find(const K &k) const;
 * @param function Iterator begin(void);
 * @param function Iterator end(void);
 */
template <typename K, typename V>
class	IMap
{
	public:
		class	Entry
		{
			public:
				virtual const K		&getKey(void) const = 0;
				virtual const V		&getValue(void) const = 0;
				/*
				 * Before jumping to quick conclusions, read about std::pair
				 * https://www.cplusplus.com/reference/utility/pair/
				 * which is the Entry type in std::unordered_map
				 */
				virtual void	setValue(const V&) = 0;
				virtual void	setKey(const K&) = 0;
				virtual ~Entry() {}
		};
		virtual int				size(void)					const = 0;
		virtual bool			empty(void)					const = 0;
		virtual const V			&at(const K&)				const = 0;
		virtual const V			&put(const K &k, const V &v) = 0;
		virtual void			erase(const K &k) = 0;
		virtual List<Entry*>	entries(void)	const = 0;
		virtual List<K>			keys(void)		const = 0;
		virtual List<V>			values(void)	const = 0;
};

#endif
