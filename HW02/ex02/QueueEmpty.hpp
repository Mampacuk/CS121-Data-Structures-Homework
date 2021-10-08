/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueEmpty.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:41:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:42:31 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUEEMPTY_HPP
# define QUEUEEMPTY_HPP

# include <exception>

class QueueEmpty : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Can't get front of/dequeue an empty queue.");
		}
};

#endif
