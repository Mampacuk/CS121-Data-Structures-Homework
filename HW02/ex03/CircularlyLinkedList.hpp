/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CircularlyLinkedList.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:21 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 18:42:43 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULARLYLINKEDLIST_HPP
# define CIRCULARLYLINKEDLIST_HPP

# include <stdlib.h>
# include <iostream>

template <typename D>
class	CircularlyLinkedList;

template <typename D>
class	CNode
{
	private:
		CNode(D data);
		D 			_data;
		CNode<D>	*_next;
		friend class CircularlyLinkedList<D>;
};

template <typename D>
CNode<D>::CNode(D data) : _data(data), _next(NULL)
{

}

template <typename D>
class	CircularlyLinkedList
{
	public:
		CircularlyLinkedList(void);
		~CircularlyLinkedList(void);
		CircularlyLinkedList(const CircularlyLinkedList &copy);
		bool		isEmpty(void)	const;
		D			&front(void)	const;
		D			&back(void)		const;
		void		advance(void);
		void		add(const D &e);
		void		remove(void);
	private:
		CNode<D>	*_cursor;
};

template <typename D>
CircularlyLinkedList<D>::CircularlyLinkedList(void) : _cursor(NULL)
{

}

template <typename D>
CircularlyLinkedList<D>::~CircularlyLinkedList(void)
{
	while (!this->isEmpty())
		this->remove();
}

template <typename D>
CircularlyLinkedList<D>::CircularlyLinkedList(const CircularlyLinkedList &copy) : _cursor(NULL)
{
	CNode<D>	*start;
	CNode<D>	*end;

	start = copy._cursor->_next;
	end = copy._cursor;
	while (1)
	{
		this->add(start->_data);
		start = start->_next;
		if (start == end)
			break ;
	}
}

template <typename D>
bool	CircularlyLinkedList<D>::isEmpty(void) const
{
	return (this->_cursor == NULL);
}

template <typename D>
D	&CircularlyLinkedList<D>::front(void) const
{
	return (this->_cursor->_next->_data);
}

template <typename D>
D	&CircularlyLinkedList<D>::back(void) const
{
	return (this->_cursor->_data);
}

template <typename D>
void	CircularlyLinkedList<D>::advance(void)
{
	this->_cursor = this->_cursor->_next;
}

template <typename D>
void	CircularlyLinkedList<D>::add(const D &e)
{
	CNode<D>	*new_node;

	new_node = new CNode<D>(e);
	if (!this->_cursor)
	{
		this->_cursor = new_node;
		new_node->_next = new_node;
	}
	else
	{
		new_node->_next = this->_cursor->_next;
		this->_cursor->_next = new_node;
	}
}

template <typename D>
void	CircularlyLinkedList<D>::remove(void)
{
	CNode<D>	*old_head;
	
	if (!this->_cursor)
		return ;
	old_head = this->_cursor->_next;
	if (old_head != this->_cursor)
		this->_cursor->_next = old_head->_next;
	else
		this->_cursor = NULL;
	delete old_head;
}

#endif
