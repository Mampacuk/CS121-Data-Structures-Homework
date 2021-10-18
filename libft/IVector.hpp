/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IVector.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:34:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/18 16:29:30 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVECTOR_HPP
# define IVECTOR_HPP

template <typename D>
class	IVector
{
	public:
		virtual const D	&at(int i)			const = 0;
		virtual const D	&operator[](int i)	const = 0;
		virtual void	set(int i, const D &e) = 0;
		virtual void	insert(int i, const D &e) = 0;
		virtual void	erase(int i) = 0;
};

#endif
