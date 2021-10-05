/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoublyLinkedList.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:37:43 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/05 20:50:56 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLINKEDLIST_HPP
# define DOUBLYLINKEDLIST_HPP

template <typename D>
class	DoublyLinkedList
{
	public:
		DoublyLinkedList(void);
		~DoublyLinkedList(void);
		DoublyLinkedList(const DoublyLinkedList<D> &copy);
		bool				empty(void)	const;
		const D				&front(void)	const;
		const D				&back(void)		const;
		void				print(void)		const;
		void				addFront(const D &e);
		void				addBack(const D &e);
		void				removeFront(void);
		void				removeBack(void);
	private:
		struct	DNode
		{
			DNode(D data) : data(data), prev(NULL), next(NULL) {}
			D		data;
			DNode	*prev;
			DNode	*next;
		};
		DNode				*_head;
		DNode				*_tail;
};

template <typename D>
DoublyLinkedList<D>::DoublyLinkedList(void) : _head(NULL), _tail(NULL)
{

}

template <typename D>
DoublyLinkedList<D>::~DoublyLinkedList(void)
{
	while (!this->empty())
		this->removeFront();
}

template <typename D>
DoublyLinkedList<D>::DoublyLinkedList(const DoublyLinkedList &copy) : _head(NULL), _tail(NULL)
{
	DNode	*curr;

	curr = copy._head;
	while (curr)
	{
		this->addBack(curr->data);
		curr = curr->next;
	}
}

template <typename D>
bool	DoublyLinkedList<D>::empty(void) const
{
	return (this->_head == NULL);
}

template <typename D>
const D	&DoublyLinkedList<D>::front(void) const
{
	return (this->_head->data);
}

template <typename D>
const D	&DoublyLinkedList<D>::back(void) const
{
	return (this->_tail->data);
}

template <typename D>
void	DoublyLinkedList<D>::addFront(const D &e)
{
	DNode	*new_head;

	if (this->empty())
		this->_head = this->_tail = new DNode(e);
	else
	{
		new_head = new DNode(e);
		this->_head->prev = new_head;
		new_head->next = this->_head;
		this->_head = new_head;
	}
}

template <typename D>
void	DoublyLinkedList<D>::addBack(const D &e)
{
	DNode	*new_tail;

	if (this->empty())
		this->_head = this->_tail = new DNode(e);
	else
	{
		new_tail = new DNode(e);
		this->_tail->next = new_tail;
		new_tail->prev = this->_tail;
		this->_tail = new_tail;
	}
}

template <typename D>
void	DoublyLinkedList<D>::removeFront(void)
{
	DNode	*old_head;

	if (this->empty())
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = this->_tail = NULL;
		return ;
	}
	old_head = this->_head;
	old_head->next->prev = NULL;
	this->_head = old_head->next;
	delete old_head;
}

template <typename D>
void	DoublyLinkedList<D>::removeBack(void)
{
	DNode	*old_tail;

	if (this->empty())
		return ;
	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = this->_tail = NULL;
		return ;
	}
	old_tail = this->_tail;
	old_tail->prev->next = NULL;
	this->_tail = old_tail->prev;
	delete old_tail;
}

template <typename D>
void	DoublyLinkedList<D>::print(void) const
{
	DNode	*curr;

	curr = this->_head;
	while (curr)
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
	if (!this->_head)
		std::cout << "(null)" << std::endl;
}

#endif