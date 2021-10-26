/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IIterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:15:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 17:10:33 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IITERATOR_HPP
# define IITERATOR_HPP

template <typename D>
class	IIterator
{
	public:
		virtual D		&operator*(void) = 0;
		virtual IIterator	&operator++(void) = 0;
		bool			operator==(const IIterator &rhs)	const
		{
			return (this->equals(rhs));
		}
		bool			operator!=(const IIterator &rhs)	const
		{
			return (!this->operator==(rhs));
		}
		virtual IIterator	&operator--(void) = 0;
	private:
		virtual bool		equals(const IIterator &rhs)		const = 0;
};

#endif
