/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:43:03 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/12 22:43:03 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

class	Integer
{
	public:
		Integer(void);
		~Integer(void);
		Integer(const Integer&);
		Integer	&operator=(const Integer&);
};

#endif
