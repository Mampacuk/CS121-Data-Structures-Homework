/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackInvalidCapacity.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:07:05 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 13:08:05 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKINVALIDCAPACITY_HPP
# define STACKINVALIDCAPACITY_HPP

class StackInvalidCapacity : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("StackInvalidCapacity: Capacity must be at least 1.");
		}
};

#endif