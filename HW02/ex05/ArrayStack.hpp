/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:44:28 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 13:45:34 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYSTACK_HPP
# define ARRAYSTACK_HPP

# define DEF_CAPACITY 100

# include "IStack.hpp"
# include "StackInvalidCapacity.hpp"
# include <iostream>

template <typename D>
class	ArrayStack : public IStack
{
	public:
		ArrayStack(void) : _arr(NULL), _cap(DEF_CAPACITY), _top(-1) {}
		ArrayStack(int cap) throw(StackInvalidCapacity);
		~ArrayStack(void);
		int		size(void)	const;
		bool	empty(void)	const;
		void	print(void)	const;
		const D	&top(void)	const throw(StackEmpty);
		void	push(const D &e) throw(StackFull);
		void	pop(void) throw(StackEmpty);
	private:
		D	*_arr;
		int	_cap;
		int	_top;
}

template <typename D>
ArrayStack<D>::ArrayStack(int cap) throw(StackInvalidCapacity)
{
	if (cap < 1)
		throw StackInvalidCapacity();
	this->_arr = new D[cap];
	this->_cap = cap;
	this->_top = -1;
}

template <typename D>
ArrayStack<D>::~ArrayStack(void)
{
	delete _arr;
}

template <typename D>
int	ArrayStack<D>::size(void) const
{
	return (this->_top + 1);
}

template <typename D>
bool	ArrayStack<D>::empty(void) const
{
	return (this->_top < 0);
}

template <typename D>
const D	&ArrayStack<D>::top(void) const throw(StackEmpty)
{
	if (this->empty())
		throw StackEmpty();
	return (this->_arr[this->_top]);
}

template <typename D>
void	ArrayStack<D>::push(const D &e) throw(StackFull)
{
	if (this->_top + 1 == this->_cap)
		throw StackFull();
	this->_arr[++this->_top] = e;
}

template <typename D>
void	ArrayStack<D>::pop(void) throw(StackEmpty)
{
	if (this->empty())
		throw StackEmpty();
	this->_top--;
}

template <typename D>
void	ArrayStack<D>::print(void)
{
	int	i;

	if (this->empty())
		std::cout << "(null)" << std::endl;
	else
	{
		i = 0;
		while (i <= this->_top)
			std::cout << this->_arr[i++] << std::endl;
	}
}

#endif