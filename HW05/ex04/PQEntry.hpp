/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PQEntry.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:59:22 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 13:59:22 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PQENTRY_HPP
# define PQENTRY_HPP

# include "../../libft/IPriorityQueue.hpp"

template <typename K, typename V>
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

#endif
