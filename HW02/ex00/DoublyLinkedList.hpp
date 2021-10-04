/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoublyLinkedList.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:37:43 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 19:55:46 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLINKEDLIST_HPP
# define DOUBLYLINKEDLIST_HPP

template <typename D>
class	DoublyLinkedList;

template <typename D>
class	DNode
{
	private:
		DNode(D data);
		D			_data;
		DNode<D>	*_prev;
		DNode<D>	*_next;
		friend class DoublyLinkedList<D>;
};

template <typename D>
DNode<D>::DNode(D data) : _data(data), _prev(NULL), _next(NULL)
{

}

template <typename D>
class	DoublyLinkedList
{
	public:
		DoublyLinkedList(void);
		~DoublyLinkedList(void);
		DoublyLinkedList(const DoublyLinkedList<D> &copy);
		bool				isEmpty(void)	const;
		const D				&front(void)	const;
		const D				&back(void)		const;
		void				print(void)		const;
		void				addFront(const D &e);
		void				addBack(const D &e);
		void				removeFront(void);
		void				removeBack(void);
	private:
		DNode<D>			*_head;
		DNode<D>			*_tail;
};

template <typename D>
DoublyLinkedList<D>::DoublyLinkedList(void) : _head(NULL), _tail(NULL)
{

}

template <typename D>
DoublyLinkedList<D>::~DoublyLinkedList(void)
{
	while (!this->isEmpty())
		this->removeFront();
}

template <typename D>
DoublyLinkedList<D>::DoublyLinkedList(const DoublyLinkedList &copy) : _head(NULL), _tail(NULL)
{
	DNode<D>	*curr;

	curr = copy._head;
	while (curr)
	{
		this->addBack(curr->_data);
		curr = curr->_next;
	}
}

template <typename D>
bool	DoublyLinkedList<D>::isEmpty(void) const
{
	return (this->_head == NULL);
}

template <typename D>
const D	&DoublyLinkedList<D>::front(void) const
{
	return (this->_head->_data);
}

template <typename D>
const D	&DoublyLinkedList<D>::back(void) const
{
	return (this->_tail->_data);
}

template <typename D>
void	DoublyLinkedList<D>::addFront(const D &e)
{
	DNode<D>	*new_head;

	if (this->isEmpty())
		this->_head = this->_tail = new DNode<D>(e);
	else
	{
		new_head = new DNode<D>(e);
		this->_head->_prev = new_head;
		new_head->_next = this->_head;
		this->_head = new_head;
	}
}

template <typename D>
void	DoublyLinkedList<D>::addBack(const D &e)
{
	DNode<D>	*new_tail;

	if (this->isEmpty())
		this->_head = this->_tail = new DNode<D>(e);
	else
	{
		new_tail = new DNode<D>(e);
		this->_tail->_next = new_tail;
		new_tail->_prev = this->_tail;
		this->_tail = new_tail;
	}
}

template <typename D>
void	DoublyLinkedList<D>::removeFront(void)
{
	DNode<D>	*old_head;

	if (this->isEmpty())
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = this->_tail = NULL;
		return ;
	}
	old_head = this->_head;
	old_head->_next->_prev = NULL;
	this->_head = old_head->_next;
	delete old_head;
}

template <typename D>
void	DoublyLinkedList<D>::removeBack(void)
{
	DNode<D>	*old_tail;

	if (this->isEmpty())
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = this->_tail = NULL;
		return ;
	}
	old_tail = this->_tail;
	old_tail->_prev->_next = NULL;
	this->_tail = old_tail->_prev;
	delete old_tail;
}

template <typename D>
void	DoublyLinkedList<D>::print(void) const
{
	DNode<D>	*curr;

	curr = this->_head;
	while (curr)
	{
		std::cout << curr->_data << std::endl;
		curr = curr->_next;
	}
	if (!this->_head)
		std::cout << "(null)" << std::endl;
}

#endif