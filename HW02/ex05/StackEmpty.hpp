/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEmpty.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:53:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 12:44:54 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKEMPTY_HPP
# define STACKEMPTY_HPP

class StackEmpty : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("StackEmpty: Can't peek at/pop from an empty stack.");
		}
};

#endif