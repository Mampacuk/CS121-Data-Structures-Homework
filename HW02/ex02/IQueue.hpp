/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IQueue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:33:46 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:45:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IQUEUE_HPP
# define IQUEUE_HPP

# include "QueueEmpty.hpp"
# include "QueueFull.hpp"
# include "QueueInvalidCapacity.hpp"

template <typename D>
class	IQueue
{
	public:
		virtual void	enqueue(const D &e) throw(QueueFull) = 0;
		virtual void	dequeue(void) throw(QueueEmpty) = 0;
		virtual const D	&front(void)	const throw(QueueEmpty) = 0;
		virtual int		size(void)		const = 0;
		virtual bool	empty(void)		const = 0;
}

#endif
