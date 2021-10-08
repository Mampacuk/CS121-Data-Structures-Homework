/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackInvalidCapacity.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:07:05 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:38:49 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKINVALIDCAPACITY_HPP
# define STACKINVALIDCAPACITY_HPP

# include <exception>

class StackInvalidCapacity : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Capacity must be at least 1.");
		}
};

#endif