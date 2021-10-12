/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IQueue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:33:46 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 17:15:52 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IQUEUE_HPP
# define IQUEUE_HPP

template <typename D>
class	IQueue
{
	public:
		virtual void	enqueue(const D &e) = 0;
		virtual void	dequeue(void) = 0;
		virtual const D	&front(void)	const = 0;
		virtual int		size(void)		const = 0;
		virtual bool	empty(void)		const = 0;
};

#endif
