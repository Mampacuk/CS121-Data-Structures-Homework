/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SinglyLinkedList.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:37:49 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/05 20:50:56 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLYLINKEDLIST_HPP
# define SINGLYLINKEDLIST_HPP

template <typename D>
class	SinglyLinkedList
{
	public:
		SinglyLinkedList(void);
		~SinglyLinkedList(void);
		SinglyLinkedList(const SinglyLinkedList &copy);
		bool				empty(void)	const;
		const D				&front(void)	const;
		const D				&back(void)		const;
		void				print(void)		const;
		void				addFront(const D &e);
		void				addBack(const D &e);
		void				removeFront(void);
		const D				&removeLast(void);
	private:
		struct	SNode
		{
			SNode(D data) : data(data), next(NULL) {}
			D		data;
			SNode	*next;
		};
		SNode				*_head;
		SNode				*_tail;
};

template <typename D>
SinglyLinkedList<D>::SinglyLinkedList(void) : _head(NULL), _tail(NULL)
{

}

template <typename D>
SinglyLinkedList<D>::~SinglyLinkedList(void)
{
	while (!this->empty())
		this->removeFront();
}

template <typename D>
SinglyLinkedList<D>::SinglyLinkedList(const SinglyLinkedList &copy) : _head(NULL), _tail(NULL)
{
	SNode	*curr;

	curr = copy._head;
	while (curr)
	{
		this->addBack(curr->data);
		curr = curr->next;
	}
}

template <typename D>
bool	SinglyLinkedList<D>::empty(void) const
{
	return (this->_head == NULL);
}

template <typename D>
const D	&SinglyLinkedList<D>::front(void) const
{
	return (this->_head->data);
}

template <typename D>
const D	&SinglyLinkedList<D>::back(void) const
{
	return (this->_tail->data);
}

template <typename D>
void	SinglyLinkedList<D>::addFront(const D &e)
{
	SNode	*new_head;

	if (this->empty())
		this->_head = this->_tail = new SNode(e);
	else
	{
		new_head = new SNode(e);
		new_head->next = this->_head;
		this->_head = new_head;
	}
}

template <typename D>
void	SinglyLinkedList<D>::addBack(const D &e)
{
	SNode	*new_tail;

	if (this->empty())
		this->_head = this->_tail = new SNode(e);
	else
	{
		new_tail = new SNode(e);
		this->_tail->next = new_tail;
		this->_tail = new_tail;
	}
}

template <typename D>
void	SinglyLinkedList<D>::removeFront(void)
{
	SNode	*old_head;

	if (this->empty())
		return ;
	old_head = this->_head;
	this->_head = old_head->next;
	delete old_head;
}

template <typename D>
const D	&SinglyLinkedList<D>::removeLast(void)
{
	SNode	*curr;
	D			&ret = this->_tail->data;			

	if (!this->_tail->next)
	{
		this->removeFront();
		return (ret);
	}
	curr = this->_head;
	while (curr->next != this->_tail)
		curr = curr->next;
	delete this->_tail;
	curr->next = NULL;
	this->_tail = curr;
	return (ret);
}

template <typename D>
void	SinglyLinkedList<D>::print(void) const
{
	SNode	*curr;

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