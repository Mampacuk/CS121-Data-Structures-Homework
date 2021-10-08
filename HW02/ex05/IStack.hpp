/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IStack.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:47:56 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 16:45:38 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISTACK_HPP
# define ISTACK_HPP

# include "StackFull.hpp"
# include "StackEmpty.hpp"
# include "StackInvalidCapacity.hpp"

template <typename D>
class	IStack
{
	public:
		virtual int		size(void)	const = 0;
		virtual bool	empty(void)	const = 0;
		virtual const D	&top(void)	const throw(StackEmpty) = 0;
		virtual void	push(const D &e) throw(StackFull) = 0;
		virtual void	pop(void) throw(StackEmpty) = 0;
};

#endif
