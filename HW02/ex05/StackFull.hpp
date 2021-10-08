/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackFull.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:41:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:38:43 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFULL_HPP
# define STACKFULL_HPP

# include <exception>

class StackFull : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Can't push to a full stack.");
		}
};

#endif