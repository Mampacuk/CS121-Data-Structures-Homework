/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringArrayPositionalList.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:20 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 20:10:59 by aisraely         ###   ########.fr       */
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

int	StringArrayPositionalList::size(void) const
{
	return (this->_n);
}

int	StringArrayPositionalList::empty(void) const
{
	return (!this->_n);
}

void	StringArrayPositionalList::insert(Position &p, const D &e)
{
	if 
}