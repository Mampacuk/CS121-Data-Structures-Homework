/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IComparator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:05:32 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 12:05:32 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICOMPARATOR_HPP
# define ICOMPARATOR_HPP

template <typename E>
class	IComparator
{
	public:
		virtual bool	operator()(const E &x, const E &y)	const = 0;
};

#endif
