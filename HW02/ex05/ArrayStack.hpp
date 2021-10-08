/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:44:28 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 18:13:36 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYSTACK_HPP
# define ARRAYSTACK_HPP

# define DEF_CAPACITY 100

# include "IStack.hpp"
# include <iostream>

template <typename D>
class	ArrayStack : public IStack<D>
{
	public:
		ArrayStack(void) : _arr(new D[DEF_CAPACITY]), _cap(DEF_CAPACITY), _top(-1) {}
		ArrayStack(int cap);
		~ArrayStack(void);
		int		size(void)	const;
		bool	empty(void)	const;
		void	print(void)	const;
		const D	&top(void)	const;
		void	push(const D &e);
		void	pop(void);
	private:
		D	*_arr;
		int	_cap;
		int	_top;
};

template <typename D>
ArrayStack<D>::ArrayStack(int cap)
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
	delete [] this->_arr;
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
const D	&ArrayStack<D>::top(void) const
{
	if (this->empty())
		throw StackEmpty();
	return (this->_arr[this->_top]);
}

template <typename D>
void	ArrayStack<D>::push(const D &e)
{
	if (this->_top + 1 == this->_cap)
		throw StackFull();
	this->_arr[++this->_top] = e;
}

template <typename D>
void	ArrayStack<D>::pop(void)
{
	if (this->empty())
		throw StackEmpty();
	this->_top--;
}

template <typename D>
void	ArrayStack<D>::print(void) const
{
	int	i;

	if (this->empty())
		std::cout << "(null)" << std::endl;
	else
	{
		i = this->_top;
		while (i >= 0)
			std::cout << this->_arr[i--] << std::endl;
	}
}

template <typename D>
void	ft_reverse_stack(ArrayStack<D> &a)
{
	ArrayStack<D>	b(a.size());
	ArrayStack<D>	c(a.size());
	
	/*
	 * b after a while contains a's elements in reversed order
	 */
	while (!a.empty())
	{
		b.push(a.top());
		a.pop();
	}
	/*
	 * c after a while contains a's elements in original order
	 */
	while (!b.empty())
	{
		c.push(b.top());
		b.pop();
	}
	/*
	 * a after a while contains a's elements in reversed order
	 */
	while (!c.empty())
	{
		a.push(c.top());
		c.pop();
	}
}

#endif
