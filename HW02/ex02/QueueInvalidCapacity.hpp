/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueInvalidCapacity.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:41:12 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 17:54:23 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUEINVALIDCAPACITY_HPP
# define QUEUEINVALIDCAPACITY_HPP

# include <exception>

class QueueInvalidCapacity : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Capacity must be at least 1.");
		}
};

#endif
