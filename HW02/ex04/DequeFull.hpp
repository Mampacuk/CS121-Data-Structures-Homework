/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeFull.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:48:51 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 17:51:24 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEFULL_HPP
# define DEQUEFULL_HPP

# include <exception>

class DequeFull : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Can't insert into a full deque.");
		}
};

#endif