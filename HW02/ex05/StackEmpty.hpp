/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEmpty.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:53:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:39:02 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKEMPTY_HPP
# define STACKEMPTY_HPP

# include <exception>

class StackEmpty : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Can't peek at/pop from an empty stack.");
		}
};

#endif