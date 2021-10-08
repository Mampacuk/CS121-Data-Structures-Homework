/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayDeque.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:01:04 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 22:03:18 by aisraely         ###   ########.fr       */
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
		ArrayDeque(void) : _arr(new D[DEF_CAPACITY]), _cap(DEF_CAPACITY), _f(0), _n(0) {}
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
		int	_n;
};

template <typename D>
ArrayDeque<D>::ArrayDeque(int cap) throw(DequeInvalidCapacity)
{
	if (cap < 1)
		throw DequeInvalidCapacity();
	this->_arr = new D[cap];
	this->_cap = cap;
	this->_n = 0;
	this->_f = 0;
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
	return (this->_arr[(this->_f + 1) % this->_cap]);
}

template <typename D>
const D	&ArrayDeque<D>::back(void) const throw(DequeEmpty)
{
	if (this->empty())
		throw DequeEmpty();
	return (this->_arr[(this->_f + this->_n) % this->_cap]);
}

template <typename D>
void	ArrayDeque<D>::insertFront(const D &e) throw(DequeFull)
{
	if (this->_n == this->_cap)
		throw DequeFull();
	this->_arr[this->_f] = e;
	// std::cout << "_f is " << this->_f << std::endl;
	// std::cout << "_cap is " << this->_cap << std::endl;
	// std::cout << "(this->_f - 1) is " << (this->_f - 1) << std::endl;
	// std::cout << "(this->_f - 1) % this->_cap is " << ((this->_f - 1) % this->_cap) << std::endl;
	this->_f = (this->_f - 1) % this->_cap;
	this->_n++;
}

// READY
template <typename D>
void	ArrayDeque<D>::insertBack(const D &e) throw(DequeFull)
{
	if (this->_n == this->_cap)
		throw DequeFull();
	this->_arr[(this->_f + this->_n + 1) % this->_cap] = e;
	this->_n++;
}

//READY
template <typename D>
void	ArrayDeque<D>::eraseFront(void) throw(DequeEmpty)
{
	if (this->empty())
		throw DequeEmpty();
	this->_f = (this->_f + 1) % this->_cap;
	this->_n--;
}

//READY
template <typename D>
void	ArrayDeque<D>::eraseBack(void) throw(DequeEmpty)
{
	if (this->empty())
		throw DequeEmpty();
	this->_n--;
}

template <typename D>
void	ArrayDeque<D>::print(void) const
{
	int	i;

	std::cout << "vvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;
	std::cout << "size: " << this->_n << "; _f: " << this->_f << std::endl;
	if (this->empty())
		std::cout << "(null)";
	else
	{
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
