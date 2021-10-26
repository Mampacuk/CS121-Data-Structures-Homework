/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DLLList.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:32:22 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 19:59:23 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLLIST_HPP
# define DLLLIST_HPP

# include "../../libft/IVector.hpp"
# include "../../libft/IIterator.hpp"

template <typename D>
class	DLLList : public IVector<D>
{
	struct	Node
	{
		D		data;
		Node	*prev;
		Node	*next;
	};
	public:
		class	Iterator : public IIterator<D>
		{
			public:
				Iterator(const Iterator &copy);
				Iterator		&operator=(const Iterator &rhs);
				D				&operator*(void);
				bool			operator==(const IIterator<D> &p)	const;
				bool			operator!=(const IIterator<D> &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
				friend class	DLLList;
			private:
				Iterator(Node *node);
				Node			*_ptr;
		};
		DLLList(void);
		~DLLList(void);
		DLLList(const DLLList &copy);
		DLLList					&operator=(const DLLList &rhs);
		const D					&operator[](int i)	const;
		const D					&at(int i)			const;
		int						size(void)			const;
		bool					empty(void)			const;
		DLLList<D>::Iterator	begin(void)	const;
		DLLList<D>::Iterator	end(void)	const;
		void					print(void)			const;
		void					erase(int i);
		void					insert(int i, const D &e);
		void					set(int i, const D &e);
	private:
		void					removeNode(Node *node);
		void					addBeforeNode(Node *node, const D &e);
		Node					*returnNode(int i)	const;
		int						_n;
		Node					*_header;
		Node					*_trailer;
};

template <typename D>
DLLList<D>::Iterator::Iterator(Node *node) : _ptr(node) {}

template <typename D>
DLLList<D>::Iterator::Iterator(const Iterator &copy) : _ptr(copy._ptr) {}

template <typename D>
typename DLLList<D>::Iterator	&DLLList<D>::Iterator::operator=(const Iterator &rhs)
{
	this->_ptr = rhs._ptr;
}

template <typename D>
D	&DLLList<D>::Iterator::operator*(void)
{
	return (this->_ptr->data);
}

template <typename D>
bool	DLLList<D>::Iterator::operator==(const IIterator<D> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);

	return (this->_ptr == it._ptr);
}

template <typename D>
bool	DLLList<D>::Iterator::operator!=(const IIterator<D> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);

	return (this->_ptr != it._ptr);
}

template <typename D>
typename DLLList<D>::Iterator	&DLLList<D>::Iterator::operator++(void)
{
	this->_ptr = this->_ptr->next->next;
	return (*this);
}

template <typename D>
typename DLLList<D>::Iterator	&DLLList<D>::Iterator::operator--(void)
{
	this->_ptr = this->_ptr->prev->prev;
	return (*this);
}

template <typename D>
typename DLLList<D>::Iterator	DLLList<D>::begin(void) const
{
	return (Iterator(this->_header->next->next));
}

template <typename D>
typename DLLList<D>::Iterator	DLLList<D>::end(void) const
{
	if (this->size() % 2 != 0)
		return (Iterator(this->_trailer));
	return (Iterator(this->_trailer->prev));
}

template <typename D>
void	DLLList<D>::removeNode(DLLList<D>::Node *node)
{
	Node	*before = node->prev;
	Node	*after = node->next;

	before->next = after;
	after->prev = before;
	delete node;
}

template <typename D>
void	DLLList<D>::addBeforeNode(DLLList<D>::Node *node, const D &e)
{
	Node	*node_prev = node->prev;
	Node	*new_node = new Node;

	new_node->data = e;
	node_prev->next = new_node;
	new_node->prev = node_prev;
	new_node->next = node;
	node->prev = new_node;
}

template <typename D>
typename DLLList<D>::Node	*DLLList<D>::returnNode(int i) const
{
	int		j;
	Node	*curr;

	j = 0;
	curr = this->_header->next;
	while (j < i)
	{
		curr = curr->next;
		j++;
	}
	return (curr);
}

template <typename D>
DLLList<D>::DLLList(void)
{
	this->_n = 0;
	this->_header = new Node;
	this->_trailer = new Node;
	this->_header->next = this->_trailer;
	this->_trailer->prev = this->_header;
}

template <typename D>
DLLList<D>::DLLList(const DLLList &copy)
{
	Node	*curr = copy._header->next;

	this->_n = 0;
	this->_header = new Node;
	this->_trailer = new Node;
	this->_header->next = this->_trailer;
	this->_trailer->prev = this->_header;
	while (curr != copy._trailer)
	{
		this->addBeforeNode(this->_trailer, curr->data);
		this->_n++;
		curr = curr->next;
	}
}

template <typename D>
DLLList<D>	&DLLList<D>::operator=(const DLLList &rhs)
{
	Node	*curr = rhs._header->next;

	while (!this->empty())
		this->erase(0);
	while (curr != rhs._trailer)
	{
		this->insert(this->size(), curr->data);
		curr = curr->next;
	}
	return (*this);
}

template <typename D>
DLLList<D>::~DLLList(void)
{
	while (!this->empty())
		this->erase(0);
	delete this->_trailer;
	delete this->_header;
}

template <typename D>
int	DLLList<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
bool	DLLList<D>::empty(void) const
{
	return (!this->_n);
}

template <typename D>
const D	&DLLList<D>::at(int i) const
{
	if (i < 0 || i >= this->size())
		throw std::out_of_range("Index is out of bounds");
	return (this->returnNode(i)->data);
}

template <typename D>
void	DLLList<D>::erase(int i)
{
	if (i < 0 || i >= this->size())
		throw std::out_of_range("Index is out of bounds");
	this->removeNode(this->returnNode(i));
	this->_n--;
}

template <typename D>
void	DLLList<D>::insert(int i, const D &e)
{
	if (i < 0 || i > this->size())
		throw std::out_of_range("Index is out of bounds");
	this->addBeforeNode(this->returnNode(i), e);
	this->_n++;
}

template <typename D>
void	DLLList<D>::set(int i, const D &e)
{
	Node	*node;

	if (i < 0 || i >= this->size())
		throw std::out_of_range("Index is out of bounds");
	node = this->returnNode(i);
	node->data = e;
}

template <typename D>
const D	&DLLList<D>::operator[](int i) const
{
	return (this->at(i));
}

template <typename D>
void	DLLList<D>::print(void) const
{
	for (Node *i = this->_header->next; i != this->_trailer; i = i->next)
		std::cout << i->data << std::endl;
}

#endif