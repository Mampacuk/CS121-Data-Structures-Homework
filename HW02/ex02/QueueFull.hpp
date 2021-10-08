/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueueFull.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:41:17 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:43:18 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUEFULL_HPP
# define QUEUEFULL_HPP

# include <exception>

class QueueFull : public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Can't enqueue a full queue.");
		}
};

#endif