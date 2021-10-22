/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IList.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:51:36 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/20 16:04:29 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIST_HPP
# define ILIST_HPP

# include "IIterator.hpp"

template <typename D>
class	IList
{
	public:
		// virtual IIterator<D>	begin(void)	const = 0;
		// virtual	IIterator<D>	end(void)	const = 0;
		virtual void			insertFront(const D &e) = 0;
		virtual void			insertBack(const D &e) = 0;
		// virtual void			insert(const IIterator<D> &p, const D &e) = 0;
		virtual void			eraseFront(void) = 0;
		virtual void			eraseBack(void) = 0;
		// virtual void			erase(const IIterator<D> &p);
};

#endif