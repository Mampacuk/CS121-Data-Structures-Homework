/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeInvalidCapacity.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:48:54 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 17:54:40 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEINVALIDCAPACITY_HPP
# define DEQUEINVALIDCAPACITY_HPP

# include <exception>

class DequeInvalidCapacity : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Capacity must be at least 1.");
		}
};

#endif