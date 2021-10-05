/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IStack.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:47:56 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/05 20:52:59 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISTACK_HPP
# define ISTACK_HPP

template <typename D>
class	IStack
{
	public:
		virtual int		size()	const = 0;
		virtual bool	empty()	const = 0;
		virtual const E	&top()	const throw(StackEmpty)
};

#endif