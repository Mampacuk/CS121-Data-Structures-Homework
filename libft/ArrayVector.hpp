/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayVector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:36:36 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 19:36:26 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYVECTOR_HPP
# define ARRAYVECTOR_HPP

# include "IVector.hpp"
# include "IIterator.hpp"
# include <exception>
# include <iostream>
# include <algorithm>

template <typename D>
class	ArrayVector : public IVector<D>
{
	public:
		class	Iterator : public IIterator<D>
		{
			public:
				Iterator(const Iterator &copy);
				Iterator(void) : _ptr(NULL) {}
				~Iterator(void) {}
				Iterator		&operator=(const Iterator &rhs);
				D				&operator*(void)					const;
				bool			operator==(const IIterator<D> &p)	const;
				bool			operator!=(const IIterator<D> &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
				friend class	ArrayVector;
			private:
				Iterator(D *_ptr);
				D			*_ptr; 
		};
		ArrayVector(void);
		~ArrayVector(void);
		ArrayVector(const ArrayVector &copy);
		ArrayVector	&operator=(const ArrayVector &rhs);
		D			&operator[](int i)	const;
		D			&at(int i)			const;
		int			size(void)			const;
		bool		empty(void)			const;
		void		print(void)			const;
		Iterator	begin(void)			const;
		Iterator	end(void)			const;
		void		erase(int i);
		void		insert(int i, const D &e);
		void		push_back(const D &e);
		void		set(int i, const D &e);
		void		reserve(int n);
	private:
		int			_capacity;
		int			_n;
		D			*_data;
};

template <typename D>
ArrayVector<D>::Iterator::Iterator(D *_ptr) : _ptr(_ptr) {}

template <typename D>
ArrayVector<D>::Iterator::Iterator(const Iterator &copy) : _ptr(copy._ptr) {}

template <typename D>
typename ArrayVector<D>::Iterator	&ArrayVector<D>::Iterator::operator=(const Iterator &rhs)
{
	this->_ptr = rhs._ptr;
	return (*this);
}

template <typename D>
bool	ArrayVector<D>::Iterator::operator==(const IIterator<D> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);

	return (this->_ptr == it._ptr);
}

template <typename D>
bool	ArrayVector<D>::Iterator::operator!=(const IIterator<D> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);

	return (this->_ptr != it._ptr);
}

template <typename D>
D	&ArrayVector<D>::Iterator::operator*(void) const
{
	return (*this->_ptr);
}

template <typename D>
typename ArrayVector<D>::Iterator	&ArrayVector<D>::Iterator::operator++(void)
{
	this->_ptr++;
	return (*this);
}

template <typename D>
typename ArrayVector<D>::Iterator	&ArrayVector<D>::Iterator::operator--(void)
{
	this->_ptr--;
	return (*this);
}

template <typename D>
typename ArrayVector<D>::Iterator	ArrayVector<D>::begin(void) const
{
	return (Iterator(this->_data));
}

template <typename D>
typename ArrayVector<D>::Iterator	ArrayVector<D>::end(void) const
{
	return (Iterator(this->_data + this->_n));
}

template <typename D>
ArrayVector<D>::ArrayVector(void) : _capacity(0), _n(0), _data(NULL) {}

template <typename D>
ArrayVector<D>::~ArrayVector(void)
{
	delete [] this->_data;
}

template <typename D>
ArrayVector<D>::ArrayVector(const ArrayVector &copy) : _capacity(0), _n(0), _data(NULL)
{
	int	i;

	i = 0;
	while (i < copy.size())
	{
		this->insert(i, copy[i]);
		i++;
	}
}

template <typename D>
ArrayVector<D>	&ArrayVector<D>::operator=(const ArrayVector &rhs)
{
	int	i;
	
	delete [] this->_data;
	this->_data = NULL;
	this->_capacity = 0;
	this->_n = 0;
	i = 0;
	while (i < rhs.size())
	{
		this->insert(i, rhs[i]);
		i++;
	}
	return (*this);
}

template <typename D>
int	ArrayVector<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
bool	ArrayVector<D>::empty(void) const
{
	return (!this->_n);
}

template <typename D>
D	&ArrayVector<D>::operator[](int i) const
{
	return (this->_data[i]);
}

template <typename D>
D	&ArrayVector<D>::at(int i) const
{
	if (i < 0 || i >= this->size())
		throw std::out_of_range("Index is out of bounds");
	return (this->_data[i]);
}

template <typename D>
void	ArrayVector<D>::erase(int i)
{
	if (i < 0 || i >= this->size())
		throw std::out_of_range("Index is out of bounds");
	i++;
	while (i < this->size())
	{
		this->_data[i - 1] = this->_data[i];
		i++;
	}
	this->_n--;
}

template <typename D>
void	ArrayVector<D>::set(int i, const D &e)
{
	if (i < 0 || i >= this->size())
		throw std::out_of_range("Index is out of bounds");
	this->_data[i] = e;
}

template <typename D>
void	ArrayVector<D>::reserve(int n)
{
	int	i;
	D	*new_data;

	if (this->_capacity >= n)
		return ;
	new_data = new D[n];
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

template <typename D>
void	ArrayVector<D>::insert(int i, const D &e)
{
	int	j;

	if (i < 0 || i > this->size())
		throw std::out_of_range("Index is out of bounds");
	if (this->size() == this->_capacity)
		this->reserve(std::max(1, this->_capacity * 2));
	j = this->size() - 1;
	while (j >= 0 && j >= i)
	{
		this->_data[j + 1] = this->_data[j];
		j--;
	}
	this->_data[i] = e;
	this->_n++;
}

template <typename D>
void	ArrayVector<D>::push_back(const D &e)
{
	this->insert(this->size(), e);
}

template <typename D>
void	ArrayVector<D>::print(void) const
{
	if (this->empty())
	{
		std::cout << "(null)";
		return ;
	}
	std::cout << "(";
	for (int i = 0; i < this->size() - 1; i++)
		std::cout << this->_data[i] << " ";
	std::cout << this->_data[this->size() - 1] << ")";
}

#endif
