/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IIterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:15:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/20 18:34:15 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IITERATOR_HPP
# define IITERATOR_HPP

template <typename D>
class	IIterator
{
	public:
		virtual D			&operator*(void) = 0;
		virtual IIterator	&operator++(void) = 0;
		// virtual bool		operator==(const IIterator &rhs)	const = 0;
		// virtual bool		operator!=(const IIterator &rhs)	const = 0;
		virtual IIterator	&operator--(void) = 0;
		virtual void		insert(const D &e) = 0;
		virtual void		erase(void) = 0;
};

#endif