/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NodeList.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:53:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/20 18:53:55 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODELIST_HPP
# define NODELIST_HPP

# include "IList.hpp"

template <typename D>
class	NodeList : public IList<D>
{
	private:
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
				D			&operator*(void);
				bool		operator==(const IIterator<D> &p)	const;
				bool		operator!=(const IIterator<D> &p)	const;
				Iterator	&operator++(void);
				Iterator	&operator--(void);
				friend class NodeList;
			private:
				Iterator(Node *node);
				Node	*_ptr; 
		};
		NodeList(void);
		~NodeList(void);
		NodeList(const NodeList &copy);
		NodeList			&operator=(const NodeList &rhs);
		int					size(void)	const;
		bool				empty(void)	const;
		IIterator<D>		begin(void)	const;
		IIterator<D>		end(void)	const;
		void				insertFront(const D &e);
		void				insertBack(const D &e);
		void				insert(const IIterator<D> &p, const D &e);
		void				eraseFront(void);
		void				eraseBack(void);
		void				erase(const IIterator<D> &p);
	private:
		int		_n;
		Node	*_header;
		Node	*_trailer;
};

template <typename D>
NodeList<D>::Iterator::Iterator(Node *node) : _ptr(node) {}

template <typename D>
D	&NodeList<D>::Iterator::operator*(void)
{
	return (this->_ptr->data);
}

template <typename D>
bool	NodeList<D>::Iterator::operator==(const IIterator<D> &p) const
{
	return (this->_ptr == static_cast<Iterator>(p)._ptr);
}

template <typename D>
bool	NodeList<D>::Iterator::operator!=(const IIterator<D> &p) const
{
	return (this->_ptr != p._ptr);
}

template <typename D>
typename NodeList<D>::Iterator	&NodeList<D>::Iterator::operator++(void)
{
	this->_ptr = this->_ptr->next;
	return (*this);
}

template <typename D>
typename NodeList<D>::Iterator	&NodeList<D>::Iterator::operator--(void)
{
	this->_ptr = this->_ptr->prev;
	return (*this);
}

template <typename D>
NodeList<D>::NodeList(void)
{
	this->_n = 0;
	this->_header = new Node;
	this->_trailer = new Node;
	this->_header->next = this->_trailer;
	this->_trailer->next = this->_header;
}

template <typename D>
NodeList<D>::~NodeList(void)
{
	while (!this->empty())
		this->eraseFront();
	delete this->_trailer;
	delete this->_header;
}

template <typename D>
int	NodeList<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
bool	NodeList<D>::empty(void) const
{
	return (!this->_n);
}

template <typename D>
IIterator<D>	NodeList<D>::begin(void) const
{
	return (Iterator(this->_header->next));
}

template <typename D>
IIterator<D>	NodeList<D>::end(void) const
{
	return (Iterator(this->_trailer));
}

template <typename D>
void	NodeList<D>::insert(const IIterator<D> &p, const D &e)
{
	Node	*it_node = ((Iterator)p)._ptr;
	Node	*it_prev = it_node->prev;
	Node	*new_node = new Node;

	new_node->data = e;
	it_prev->next = new_node;
	new_node->prev = it_prev;
	new_node->next = it_node;
	it_node->prev = new_node;
	this->_n++;
}

template <typename D>
void	NodeList<D>::insertFront(const D &e)
{
	this->insert(this->begin(), e);
}

template <typename D>
void	NodeList<D>::insertBack(const D &e)
{
	this->insert(this->end(), e);
}

template <typename D>
void	NodeList<D>::erase(const IIterator<D> &p)
{
	Node	*it_node = ((Iterator)p)._ptr;
	Node	*it_before = it_node->prev;
	Node	*it_after = it_node->next;

	it_before->next = it_after;
	it_after->prev = it_before;
	delete it_node;
	this->_n--;
}

template <typename D>
void	NodeList<D>::eraseFront(void)
{
	this->erase(this->begin());
}

template <typename D>
void	NodeList<D>::eraseBack(void)
{
	this->erase(--this->end());
}

#endif