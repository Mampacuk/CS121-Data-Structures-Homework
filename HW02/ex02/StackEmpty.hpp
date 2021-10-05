/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackEmpty.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:53:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/05 20:54:55 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKEMPTY_HPP
# define STACKEMPTY_HPP

class StackEmpty : public std::exception
{
	public:
	StackEmpty(const string& err) :  {}
};

#endif