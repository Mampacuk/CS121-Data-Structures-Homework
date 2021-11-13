/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IIterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:15:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 17:52:41 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IITERATOR_HPP
# define IITERATOR_HPP

template <typename D>
class	IIterator
{
	public:
		virtual IIterator	&operator++(void) = 0;
		virtual D			&operator*(void)					const = 0;
		virtual bool		operator==(const IIterator &rhs)	const = 0;
		virtual bool		operator!=(const IIterator &rhs)	const = 0;
		virtual IIterator	&operator--(void) = 0;
};

#endif
