/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayQueue.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:33:43 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 18:13:21 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYQUEUE_HPP
# define ARRAYQUEUE_HPP

# define DEF_CAPACITY 100

# include "IQueue.hpp"
# include <iostream>

template <typename D>
class	ArrayQueue : public IQueue<D>
{
	public:
		ArrayQueue(void) : _arr(new D[DEF_CAPACITY]), _cap(DEF_CAPACITY), _n(0) {}
		ArrayQueue(int cap);
		~ArrayQueue(void);
		int		size(void)		const;
		bool	empty(void)		const;
		void	print(void)		const;
		const D	&front(void)	const;
		void	enqueue(const D &e);
		void	dequeue(void);
	private:
		D	*_arr;
		int	_cap;
		int	_n;
};

template <typename D>
ArrayQueue<D>::ArrayQueue(int cap)
{
	if (cap < 1)
		throw QueueInvalidCapacity();
	this->_arr = new D[cap];
	this->_cap = cap;
	this->_n = 0;
}

template <typename D>
ArrayQueue<D>::~ArrayQueue(void)
{
	delete [] this->_arr;
}

template <typename D>
bool	ArrayQueue<D>::empty(void) const
{
	return (this->_n < 1);
}

template <typename D>
int	ArrayQueue<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
const D	&ArrayQueue<D>::front(void) const
{
	if (this->empty())
		throw QueueEmpty();
	return (*this->_arr);
}

template <typename D>
void	ArrayQueue<D>::enqueue(const D &e)
{
	if (this->_n == this->_cap)
		throw QueueFull();
	this->_arr[this->_n++] = e;
}

template <typename D>
void	ArrayQueue<D>::dequeue(void)
{
	int	i;
	
	if (this->empty())
		throw QueueEmpty();
	i = 1;
	while (i < this->_n)
	{
		this->_arr[i - 1] = this->_arr[i];
		i++;
	}
	this->_n--;
}

template <typename D>
void	ArrayQueue<D>::print(void) const
{
	int	i;

	if (this->empty())
		std::cout << "(null)";
	else
	{
		i = 0;
		while (i < this->_n)
			std::cout << this->_arr[i++] << " ";
	}
	std::cout << std::endl;
}

#endif
