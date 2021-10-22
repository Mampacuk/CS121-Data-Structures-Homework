/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NodeList.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:53:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/20 20:26:52 by aisraely         ###   ########.fr       */
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
				D				&operator*(void);
				bool			operator==(const NodeList<D>::Iterator &p)	const;
				bool			operator!=(const NodeList<D>::Iterator &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
				void			insert(const D &e);
				void			erase(void);
				friend class	NodeList;	// don't want to use `friend`!!
			private:
				Iterator(Node *node);
				Node			*_ptr; 
		};
		NodeList(void);
		~NodeList(void);
		NodeList(const NodeList &copy);
		NodeList				&operator=(const NodeList &rhs);
		int						size(void)	const;
		bool					empty(void)	const;
		NodeList<D>::Iterator	begin(void)	const;
		NodeList<D>::Iterator	end(void)	const;
		void					insertFront(const D &e);
		void					insertBack(const D &e);
		void					insert(Iterator &p, const D &e);
		void					eraseFront(void);
		void					eraseBack(void);
		void					erase(Iterator &p);
	private:
		int						_n;
		Node					*_header;
		Node					*_trailer;
};

template <typename D>
NodeList<D>::Iterator::Iterator(Node *node) : _ptr(node) {}

template <typename D>
D	&NodeList<D>::Iterator::operator*(void)
{
	return (this->_ptr->data);
}

template <typename D>
bool	NodeList<D>::Iterator::operator==(const NodeList<D>::Iterator &p) const
{
	return (this->_ptr == p._ptr);
}

template <typename D>
bool	NodeList<D>::Iterator::operator!=(const NodeList<D>::Iterator &p) const
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
void	NodeList<D>::Iterator::insert(const D &e)
{
	Node	*it_prev = this->_ptr->prev;
	Node	*new_node = new Node;

	new_node->data = e;
	it_prev->next = new_node;
	new_node->prev = it_prev;
	new_node->next = this->_ptr;
	this->_ptr->prev = new_node;
}

template <typename D>
void	NodeList<D>::Iterator::erase(void)
{
	Node	*it_before = this->_ptr->prev;
	Node	*it_after = this->_ptr->next;

	it_before->next = it_after;
	it_after->prev = it_before;
	delete this->_ptr;
	this->_ptr = it_after;
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
typename NodeList<D>::Iterator	NodeList<D>::begin(void) const
{
	return (Iterator(this->_header->next));
}

template <typename D>
typename NodeList<D>::Iterator	NodeList<D>::end(void) const
{
	return (Iterator(this->_trailer));
}

template <typename D>
void	NodeList<D>::insert(Iterator &p, const D &e)
{
	p.insert(e);
	this->_n++;
}

template <typename D>
void	NodeList<D>::erase(Iterator &p)
{
	p.erase();
	this->_n--;
}

template <typename D>
void	NodeList<D>::insertFront(const D &e)
{
	Iterator	first = this->begin();

	this->insert(first, e);
}

template <typename D>
void	NodeList<D>::insertBack(const D &e)
{
	Iterator	last = this->end();

	this->insert(last, e);
}

template <typename D>
void	NodeList<D>::eraseFront(void)
{
	Iterator	first = this->begin();

	this->erase(first);
}

template <typename D>
void	NodeList<D>::eraseBack(void)
{
	Iterator	last = --this->end();

	this->erase(last);
}

#endif