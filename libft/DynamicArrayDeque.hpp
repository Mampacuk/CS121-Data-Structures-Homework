/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DynamicArrayDeque.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:19:53 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/12 20:19:53 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMICARRAYDEQUE_HPP
# define DYNAMICARRAYDEQUE_HPP

# define DEFAULT_DEQUE_CAPACITY 20

# include "IDeque.hpp"
# include <iostream>

template <typename D>
class	DynamicArrayDeque : public IDeque<D>
{
	public:
		DynamicArrayDeque(void) : _arr(new D[DEFAULT_DEQUE_CAPACITY]), _cap(DEFAULT_DEQUE_CAPACITY), _f(0), _n(0) {}
		DynamicArrayDeque(int cap);
		~DynamicArrayDeque(void);
		int		size(void)		const;
		bool	empty(void)		const;
		void	print(void)		const;
		const D &front(void)	const;
		const D	&back(void)		const;
		void	insertFront(const D &e);
		void	insertBack(const D &e);
		void	eraseFront(void);
		void	eraseBack(void);
	private:
		class DequeEmpty : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("Can't get the back or front/erase from an empty deque.");
				}
		};
		class DequeInvalidCapacity : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("Capacity must be at least 1.");
				}
		};
		void	resize(void);
		D		*_arr;
		int 	_cap;
		int		_f;
		int		_n;
};

template <typename D>
void	DynamicArrayDeque<D>::resize(void)
{
	int	i;
	D	*data;

	data = new D[this->_cap * 2];
	i = 0;
	for (int j = this->_f + 1; j < this->_cap; j++, i++)
		data[i] = this->_arr[j];
	for (int k = 0; k <= this->_f && k < this->_cap; k++, i++)
		data[i] = this->_arr[k];
	delete [] this->_arr;
	this->_arr = data;
	this->_cap *= 2;
	this->_f = this->_cap - 1;
}

template <typename D>
DynamicArrayDeque<D>::DynamicArrayDeque(int cap)
{
	if (cap < 1)
		throw DequeInvalidCapacity();
	this->_arr = new D[cap];
	this->_cap = cap;
	this->_n = 0;
	this->_f = 0;
}

template <typename D>
DynamicArrayDeque<D>::~DynamicArrayDeque(void)
{
	delete [] this->_arr;
}

template <typename D>
bool	DynamicArrayDeque<D>::empty(void) const
{
	return (this->_n < 1);
}

template <typename D>
int	DynamicArrayDeque<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
const D	&DynamicArrayDeque<D>::front(void) const
{
	if (this->empty())
		throw DequeEmpty();
	return (this->_arr[(this->_f + 1) % this->_cap]);
}

template <typename D>
const D	&DynamicArrayDeque<D>::back(void) const
{
	if (this->empty())
		throw DequeEmpty();
	return (this->_arr[(this->_f + this->_n) % this->_cap]);
}

template <typename D>
void	DynamicArrayDeque<D>::insertFront(const D &e)
{
	if (this->_n == this->_cap)
		this->resize();
	this->_arr[this->_f] = e;
	if (!this->_f)
		this->_f = this->_cap - 1;
	else
		this->_f = (this->_f - 1) % this->_cap;
	this->_n++;
}

template <typename D>
void	DynamicArrayDeque<D>::insertBack(const D &e)
{
	if (this->_n == this->_cap)
		this->resize();
	this->_arr[(this->_f + this->_n + 1) % this->_cap] = e;
	this->_n++;
}

template <typename D>
void	DynamicArrayDeque<D>::eraseFront(void)
{
	if (this->empty())
		throw DequeEmpty();
	this->_f = (this->_f + 1) % this->_cap;
	this->_n--;
}

template <typename D>
void	DynamicArrayDeque<D>::eraseBack(void)
{
	if (this->empty())
		throw DequeEmpty();
	this->_n--;
}

template <typename D>
void	DynamicArrayDeque<D>::print(void) const
{
	int	i;

	std::cout << "vvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;
	std::cout << "size: " << this->_n << "; _f: " << this->_f << "; cap: " << this->_cap << std::endl;
	if (this->empty())
		std::cout << "(null)";
	else
	{
		std::cout << "front(): " << this->front() << std::endl;
		std::cout << "back(): " << this->back() << std::endl;
		i = 0;
		while (i < this->_cap)
		{
			std::cout << i << ":" << this->_arr[i] << " ";
			i++;
		}
	}
	std::cout << std::endl << "^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
}

#endif
