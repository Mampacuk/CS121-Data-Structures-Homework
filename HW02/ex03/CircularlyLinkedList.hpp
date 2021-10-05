/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CircularlyLinkedList.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:21 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/05 20:50:56 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULARLYLINKEDLIST_HPP
# define CIRCULARLYLINKEDLIST_HPP

# include <stdlib.h>
# include <iostream>

template <typename D>
class	CircularlyLinkedList
{
	public:
		CircularlyLinkedList(void);
		~CircularlyLinkedList(void);
		CircularlyLinkedList(const CircularlyLinkedList &copy);
		bool		empty(void)	const;
		D			&front(void)	const;
		D			&back(void)		const;
		void		advance(void);
		void		add(const D &e);
		void		remove(void);
	private:
		struct	CNode
		{
			CNode(D data) : data(data), next(NULL) {}
			D 		data;
			CNode	*next;
		};
		CNode	*_cursor;
};

template <typename D>
CircularlyLinkedList<D>::CircularlyLinkedList(void) : _cursor(NULL)
{

}

template <typename D>
CircularlyLinkedList<D>::~CircularlyLinkedList(void)
{
	while (!this->empty())
		this->remove();
}

template <typename D>
CircularlyLinkedList<D>::CircularlyLinkedList(const CircularlyLinkedList &copy) : _cursor(NULL)
{
	CNode	*start;
	CNode	*end;

	start = copy._cursor->next;
	end = copy._cursor;
	while (1)
	{
		this->add(start->data);
		start = start->next;
		if (start == end)
			break ;
	}
}

template <typename D>
bool	CircularlyLinkedList<D>::empty(void) const
{
	return (this->_cursor == NULL);
}

template <typename D>
D	&CircularlyLinkedList<D>::front(void) const
{
	return (this->_cursor->next->data);
}

template <typename D>
D	&CircularlyLinkedList<D>::back(void) const
{
	return (this->_cursor->data);
}

template <typename D>
void	CircularlyLinkedList<D>::advance(void)
{
	this->_cursor = this->_cursor->next;
}

template <typename D>
void	CircularlyLinkedList<D>::add(const D &e)
{
	CNode	*new_node;

	new_node = new CNode(e);
	if (!this->_cursor)
	{
		this->_cursor = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = this->_cursor->next;
		this->_cursor->next = new_node;
	}
}

template <typename D>
void	CircularlyLinkedList<D>::remove(void)
{
	CNode	*old_head;
	
	if (!this->_cursor)
		return ;
	old_head = this->_cursor->next;
	if (old_head != this->_cursor)
		this->_cursor->next = old_head->next;
	else
		this->_cursor = NULL;
	delete old_head;
}

#endif
