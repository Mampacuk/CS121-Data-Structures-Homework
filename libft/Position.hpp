/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:14:35 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/06 19:14:35 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_HPP
# define POSITION_HPP

template <typename E>
class	Position
{
	public:
		virtual E	&operator*() const = 0;
};

#endif
