/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringArrayPositionalList.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:20 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 21:39:10 by aisraely         ###   ########.fr       */
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

std::string	&StringArrayPositionalList::Position::operator*(void)
{
	return (*this->_str)
}

bool	StringArrayPositionalList::Position::operator==(const IIterator<std::string> &p) const
{
	if (typeid(p) != typeid(StringArrayPositionalList::Position))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const StringArrayPositionalList::Position&>(p);

	return (this->_i == it._i && this->_str == it._str);
}

bool	StringArrayPositionalList::Position::operator==(const IIterator<std::string> &p) const
{
	if (typeid(p) != typeid(StringArrayPositionalList::Position))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const StringArrayPositionalList::Position&>(p);

	return (!(this->_i == it._i && this->_str == it._str));
}

StringArrayPositionalList::Position	&StringArrayPositionalList::Position::operator++(void)
{
	this->_i++;
	if (this->_str)
		this->_str++;
	return (*this);
}

StringArrayPositionalList::Position	&StringArrayPositionalList::Position::operator--(void)
{
	this->_i--;
	if (this->_str)
		this->_str--;
	return (*this);
}

void	StringArrayPositionalList::reserve(int n)
{
	int			i;
	std::string	*new_data;

	if (this->_capacity >= n)
		return ;
	new_data = new std::string[n];
	i = 0;
	while (i < this->size())
	{
		new_data[i] = this->_data[i];
		i++;
	}
	if (this->_data)
		delete [] this->_data;
	this->_data = new_data;
	this->_capacity = n;
}

void	StringArrayPositionalList::insert(const IIterator<std::string> &p, const std::string &e)
{
	if (typeid(p) != typeid(StringArrayPositionalList::Position))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const StringArrayPositionalList::Position&>(p);
	if (it._i < 0 || it._i > this->size())
		throw std::out_of_range("Index is out of bounds");
	
	if (this->size() == this->_capacity)
		this->reserve(ft_max(1, this->_capacity * 2));

	int	j = this->size() - 1;
	while (j >= 0 && j >= it._i)
	{
		this->_data[j + 1] = this->_data[j];
		this->_data[j + 1]._i++;
		j--;
	}
	this->_data[it._i] = new StringArrayPositionalList::Position(it._i, &e);
	this->_n++;
}

StringArrayPositionalList::Position	StringArrayPositionalList::begin(void)	const
{
	if (this->empty())
		return (this->end());
	return (this->_data[0]);
}

StringArrayPositionalList::Position	StringArrayPositionalList::end(void)	const
{
	return (StringArrayPositionalList::Position(this->size(), NULL));
}

void	StringArrayPositionalList::insertFront(const D &e)
{
	StringArrayPositionalList::Position	first = this->begin();

	this->insert(first, e);
}

void	StringArrayPositionalList::insertBack(const D &e)
{
	StringArrayPositionalList::Position	last = this->end();

	this->insert(last, e);
}

void	StringArrayPositionalList::eraseFront(void)
{
	StringArrayPositionalList::Position	first = this->begin();

	this->erase(first);
}

void	StringArrayPositionalList::eraseBack(void)
{
	Iterator	last = --this->end();

	this->erase(last);
}

void	StringArrayPositionalList::erase(const IIterator<std::string> &p)
{
	if (typeid(p) != typeid(StringArrayPositionalList::Position))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const StringArrayPositionalList::Position&>(p);
	if (it._i < 0 || it._i >= this->size())
		throw std::out_of_range("Index is out of bounds");

	int	i = it._i + 1;
	while (i < this->size())
	{
		this->_data[i - 1] = this->_data[i];
		this->_data[i - 1]._i--;
		i++;
	}
	delete p;
	this->_n--;
}
