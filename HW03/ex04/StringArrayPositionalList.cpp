/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringArrayPositionalList.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:20 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 19:36:58 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringArrayPositionalList.hpp"

StringArrayPositionalList::StringArrayPositionalList(void) : _capacity(0), _n(0), _data(NULL) {}

StringArrayPositionalList::~StringArrayPositionalList(void)
{
	delete [] this->_data;
}

// StringArrayPositionalList::StringArrayPositionalList(const StringArrayPositionalList &copy) : _capacity(0), _n(0), _data(NULL)
// {
	
// }