/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayDeque.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:01:04 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 18:38:38 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYDEQUE_HPP
# define ARRAYDEQUE_HPP

# define DEF_CAPACITY 100

# include "IDeque.hpp"
# include <iostream>

template <typename D>
class	ArrayDeque : public IDeque<D>
{
	public:
		ArrayDeque(void) : _arr(new D[DEF_CAPACITY]), _f(-1), _r(-1), _n(0) {}
		ArrayDeque(int cap) throw(DequeInvalidCapacity);
		~ArrayDeque(void);
		int		size(void)		const;
		bool	empty(void)		const;
		void	print(void)		const;
		const D &front(void)	const throw(DequeEmpty);
		const D	&back(void)		const throw(DequeEmpty);
		void	insertFront(const D &e) throw(DequeFull);
		void	insertBack(const D &e) throw(DequeFull);
		void	eraseFront(void) throw(DequeEmpty);
		void	eraseBack(void) throw(DequeEmpty);
	private:
		D	*_arr;
		int _cap;
		int	_f;
		int	_r;
		int	_n;
}

template <typename D>
ArrayDeque<D>::ArrayDeque(int cap) throw(DequeInvalidCapacity)
{
	if (cap < 1)
		throw QueueInvalidCapacity();
	this->_arr = new D[cap];
	this->_cap = cap;
	this->_n = 0;
	this->_f = -1;
	this->_r = -1;
}

template <typename D>
ArrayDeque<D>::~ArrayDeque(void)
{
	delete [] this->_arr;
}

template <typename D>
bool	ArrayDeque<D>::empty(void) const
{
	return (this->_n < 1);
}

template <typename D>
int	ArrayDeque<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
const D	&ArrayDeque<D>::front(void) const throw(DequeEmpty)
{
	if (this->empty())
		throw DequeEmpty();
	return (this->_arr[this->_f]);
}

template <typename D>
const D	&ArrayDeque<D>::back(void) const throw(DequeEmpty)
{
	if (this->empty())
		throw DequeEmpty();
	return (this->_arr[this->_r]);
}

template <typename D>
void	ArrayDeque<D>::insertFront(const D &e) throw(DequeFull)
{
	int	new_f;

	if (this->_n++ == this->_cap)
		throw DequeFull();
	new_f = (this->_f - 1) % this->_cap;
	this->_arr[new_f] = e;
	this->_f = new_f;
}

template <typename D>
void	ArrayDeque<D>::insertBack(const D &e) throw(DequeFull)
{
	int	new_r;

	if (this->_n++ == this->_cap)
		throw DequeFull();
	new_r = (this->_r + 1) % this->_cap;
	this->_arr[new_r] = e;
	this->_r = new_r;
}

template <typename D>
void	ArrayDeque<D>::eraseFront(void) throw(DequeEmpty)
{
	if (this->_n-- < 0)
		throw DequeEmpty();
	this->_f = (this->_f + 1) % this->_cap;
}

template <typename D>
void	ArrayDeque<D>::eraseBack(void) throw(DequeEmpty)
{
	if (this->_n-- < 0)
		throw DequeEmpty();
	this->_f = (this->_f - 1) % this->_cap;
}

template <typename D>
void	ArrayDeque<D>::print(void) const
{
	int	i;

	if (this->empty())
		std::cout << "(null)";
	else
	{
		i = this->_f;
		while (i < this->_cap - 1)
			std::cout << this->_arr[i++] << " ";
		i = 0;
		while (i >= this->_r)
			std::cout << this->_arr[i++] << " ";
	}
	std::cout << std::endl;
}

#endif
