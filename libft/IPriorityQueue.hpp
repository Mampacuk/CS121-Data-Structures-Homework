/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPriorityQueue.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:38:52 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/23 22:38:52 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPRIORITYQUEUE_HPP
# define IPRIORITYQUEUE_HPP

template <typename K, typename V>
class	IPriorityQueue
{
	public:
		class	Entry
		{
			public:
				virtual const K	&getKey(void)	const = 0;
				virtual const V	&getValue(void)	const = 0;
				virtual ~Entry(void) {}
		};
		virtual void	insert(const K &key, const V &value) = 0;
		virtual void	removeMin(void) = 0;
		virtual	Entry	*min(void)	const = 0;
		virtual int		size(void)	const = 0;
		virtual bool	empty(void)	const = 0;
		virtual ~IPriorityQueue(void) {}
};

#endif
