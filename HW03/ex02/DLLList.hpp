/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DLLList.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:32:22 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 17:25:44 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLLIST_HPP
# define DLLLIST_HPP

# include "../../libft/IVector.hpp"

template <typename D>
class	DLLList : public IVector<D>
{
	public:
		DLLList(void);
		~DLLList(void);
		DLLList(const DLLList &copy);
		DLLList	&operator=(const DLLList &rhs);
		const D	&operator[](int i)	const;
		const D	&at(int i)			const;
		int		size(void)			const;
		bool	empty(void)			const;
		void	print(void)			const;
		void	erase(int i);
		void	insert(int i, const D &e);
		void	set(int i, const D &e);
	private:
		struct	Node
		{
			D		data;
			Node	*prev;
			Node	*next;
		};
		void	removeNode(Node *node);
		void	addBeforeNode(Node *node, const D &e);
		Node	*returnNode(int i)	const;
		int		_n;
		Node	*_header;
		Node	*_trailer;
};

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