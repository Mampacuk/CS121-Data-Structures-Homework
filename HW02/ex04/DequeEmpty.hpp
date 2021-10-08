/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeEmpty.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:48:47 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 18:42:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEEMPTY_HPP
# define DEQUEEMPTY_HPP

# include <exception>

class DequeEmpty : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Can't get get the back or front/erase from an empty deque.");
		}
};

#endif