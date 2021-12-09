/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:55:17 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/09 21:55:17 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDSTACK_HPP
# define LINKEDSTACK_HPP

# include "IStack.hpp"
# include <exception>

template <typename D>
class	LinkedStack : public IStack<D>
{
	public:
		int		size()	const { return (this->_size); }
		bool	empty()	const { return (!this->_size); }
		const D	&top()	const;
		void	push(const D &e);
		void	pop();
		void	print() const;
		LinkedStack();
		~LinkedStack();
	private:
		struct	Node
		{
			Node(D data, Node *next) : data(data), next(next) {}
			D		data;
			Node	*next;
		};
		int		_size;
		Node	*_head;
};

template <typename D>
LinkedStack<D>::LinkedStack() : _size(0), _head(nullptr) {}

template <typename D>
LinkedStack<D>::~LinkedStack()
{
	while (!this->empty())
		this->pop();
}

template <typename D>
const D	&LinkedStack<D>::top() const
{
	if (this->empty())
		throw std::logic_error("cannot peek at an empty stack");
	return (this->_head->data);
}

template <typename D>
void	LinkedStack<D>::push(const D &e)
{
	this->_head = new Node(e, this->_head);
	this->_size++;
}

template <typename D>
void	LinkedStack<D>::pop()
{
	if (this->empty())
		throw std::logic_error("cannot remove from an empty stack");
	Node	*removed = this->_head;
	this->_head = this->_head->next;
	delete removed;
	this->_size--;
}

template <typename D>
void	LinkedStack<D>::print() const
{
	Node	*curr = this->_head;

	while (curr)
	{
		std::cout << " " << curr->data;
		curr = curr->next;
	}
}

#endif
