/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackFull.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:41:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 12:45:04 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFULL_HPP
# define STACKFULL_HPP

class StackFull : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("StackFull: Can't push to an full stack.");
		}
};

#endif