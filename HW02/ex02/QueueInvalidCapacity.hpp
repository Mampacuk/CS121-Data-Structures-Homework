/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueInvalidCapacity.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:41:12 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:44:20 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUEVALIDCAPACITY_HPP
# define QUEUEINVALIDCAPACITY_HPP

# include <exception>

class QueueInvalidCapacity : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Capacity must be at least 1.");
		}
};

#endif