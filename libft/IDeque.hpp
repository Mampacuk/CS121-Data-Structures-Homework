/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDeque.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:48:57 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 18:10:17 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDEQUE_HPP
# define IDEQUE_HPP

template <typename D>
class	IDeque
{
	public:
		virtual void	insertFront(const D &e) = 0;
		virtual void	insertBack(const D &e) = 0;
		virtual void	eraseFront(void) = 0;
		virtual void	eraseBack(void) = 0;
		virtual const D	&front(void)	const = 0;
		virtual const D &back(void)		const = 0;
		virtual int		size(void)		const = 0;
		virtual bool	empty(void)		const = 0;
};

#endif
