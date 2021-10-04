/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SinglyLinkedList.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:37:49 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 15:53:40 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLYLINKEDLIST_HPP
# define SINGLYLINKEDLIST_HPP

template <typename D>
class	SinglyLinkedList;

template <typename D>
class	SNode
{
	private:
		SNode(D data);
		D			_data;
		SNode<D>	*_next;
		friend class SinglyLinkedList<D>;
};

template <typename D>
SNode<D>::SNode(D data) : _data(data), _next(NULL)
{

}

template <typename D>
class	SinglyLinkedList
{
	public:
		SinglyLinkedList(void);
		~SinglyLinkedList(void);
		SinglyLinkedList(const SinglyLinkedList &copy);
		bool				isEmpty(void)	const;
		D					*front(void)	const;
		D					*back(void)		const;
		void				print(void)		const;
		void				addFront(const D &e);
		void				addBack(const D &e);
		void				removeFront(void);
		D					*removeLast(void);
	private:
		class	ReadingEmptyListException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("ReadingEmptyListException: No elements can be read "
					"from an empty list.");
				}
		};
		SNode<D>			*_head;
		SNode<D>			*_tail;
};

template <typename D>
SinglyLinkedList<D>::SinglyLinkedList(void) : _head(NULL), _tail(NULL)
{

}

template <typename D>
SinglyLinkedList<D>::~SinglyLinkedList(void)
{
	while (!this->isEmpty())
		this->removeFront();
}

template <typename D>
SinglyLinkedList<D>::SinglyLinkedList(const SinglyLinkedList &copy) : _head(NULL), _tail(NULL)
{
	SNode<D>	*curr;

	curr = copy._head;
	while (curr)
	{
		this->addBack(curr->_data);
		curr = curr->_next;
	}
}

template <typename D>
bool	SinglyLinkedList<D>::isEmpty(void) const
{
	return (this->_head == NULL);
}

template <typename D>
D	*SinglyLinkedList<D>::front(void) const
{
	try
	{
		if (this->_head)
			return (&this->_head->_data);
		throw ReadingEmptyListException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}

template <typename D>
D	*SinglyLinkedList<D>::back(void) const
{
	try
	{
		if (this->_head)
			return (&this->_tail->_data);
		throw ReadingEmptyListException();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}

template <typename D>
void	SinglyLinkedList<D>::addFront(const D &e)
{
	SNode<D>	*new_head;

	if (this->isEmpty())
		this->_head = this->_tail = new SNode<D>(e);
	else
	{
		new_head = new SNode<D>(e);
		new_head->_next = this->_head;
		this->_head = new_head;
	}
}

template <typename D>
void	SinglyLinkedList<D>::addBack(const D &e)
{
	SNode<D>	*new_tail;

	if (this->isEmpty())
		this->_head = this->_tail = new SNode<D>(e);
	else
	{
		new_tail = new SNode<D>(e);
		this->_tail->_next = new_tail;
		this->_tail = new_tail;
	}
}

template <typename D>
void	SinglyLinkedList<D>::removeFront(void)
{
	SNode<D>	*old_head;

	if (this->isEmpty())
		return ;
	old_head = this->_head;
	this->_head = old_head->_next;
	delete old_head;
}

template <typename D>
D	*SinglyLinkedList<D>::removeLast(void)
{
	D			*ret;
	SNode<D>	*curr;

	ret = NULL;
	if (this->isEmpty())
		return (NULL);
	if (!this->_tail->_next)
	{
		ret = &this->_head->_data;
		this->removeFront();
		return (ret);
	}
	curr = this->_head;
	while (curr->_next != this->_tail)
		curr = curr->_next;
	ret = &this->_tail->_data;
	delete this->_tail;
	curr->_next = NULL;
	this->_tail = curr;
	return (ret);
}

template <typename D>
void	SinglyLinkedList<D>::print(void) const
{
	SNode<D>	*curr;

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