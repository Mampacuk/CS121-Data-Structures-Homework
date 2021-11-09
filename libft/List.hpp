/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:47:19 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/30 15:24:45 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "IList.hpp"
# include <iostream>
# include <exception>

template <typename D>
class	List : public IList<D>
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
				~Iterator(void) {}
				Iterator		&operator=(const Iterator &rhs);
				D				&operator*(void);
				bool			operator==(const IIterator<D> &p)	const;
				bool			operator!=(const IIterator<D> &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
				friend class	List;
			private:
				Iterator(const Iterator &copy);
				Iterator(Node *node);
				Node			*_ptr; 
		};
		List(void);
		~List(void);
		List(const List &copy);
		List		&operator=(const List &rhs);
		int			size(void)	const;
		bool		empty(void)	const;
		Iterator	begin(void)	const;
		Iterator	end(void)	const;
		void		print(void)	const;
		void		insertFront(const D &e);
		void		insertBack(const D &e);
		void		insert(const IIterator<D> &p, const D &e);
		void		eraseFront(void);
		void		eraseBack(void);
		void		erase(const IIterator<D> &p);
	private:
		int			_n;
		Node		*_header;
		Node		*_trailer;
};

template <typename D>
List<D>::Iterator::Iterator(Node *node) : _ptr(node) {}

template <typename D>
List<D>::Iterator::Iterator(const Iterator &copy) : _ptr(copy._ptr) {}

template <typename D>
typename List<D>::Iterator	&List<D>::Iterator::operator=(const Iterator &rhs)
{
	this->_ptr = rhs._ptr;
}

template <typename D>
bool	List<D>::Iterator::operator==(const IIterator<D> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);

	return (this->_ptr == it._ptr);
}

template <typename D>
bool	List<D>::Iterator::operator!=(const IIterator<D> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);

	return (this->_ptr != it._ptr);
}

template <typename D>
D	&List<D>::Iterator::operator*(void)
{
	return (this->_ptr->data);
}

template <typename D>
typename List<D>::Iterator	&List<D>::Iterator::operator++(void)
{
	this->_ptr = this->_ptr->next;
	return (*this);
}

template <typename D>
typename List<D>::Iterator	&List<D>::Iterator::operator--(void)
{
	this->_ptr = this->_ptr->prev;
	return (*this);
}

template <typename D>
List<D>::List(void)
{
	this->_n = 0;
	this->_header = new Node;
	this->_trailer = new Node;
	this->_header->next = this->_trailer;
	this->_trailer->prev = this->_header;
}

template <typename D>
List<D>::~List(void)
{
	while (!this->empty())
		this->eraseFront();
	delete this->_trailer;
	delete this->_header;
}

template <typename D>
int	List<D>::size(void) const
{
	return (this->_n);
}

template <typename D>
bool	List<D>::empty(void) const
{
	return (!this->_n);
}

template <typename D>
typename List<D>::Iterator	List<D>::begin(void) const
{
	return (Iterator(this->_header->next));
}

template <typename D>
typename List<D>::Iterator	List<D>::end(void) const
{
	return (Iterator(this->_trailer));
}

template <typename D>
void	List<D>::insert(const IIterator<D> &p, const D &e)
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();

	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	Node			*it_prev = it._ptr->prev;
	Node			*new_node = new Node;

	new_node->data = e;
	it_prev->next = new_node;
	new_node->prev = it_prev;
	new_node->next = it._ptr;
	it._ptr->prev = new_node;
	this->_n++;
}

template <typename D>
void	List<D>::erase(const IIterator<D> &p)
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();

	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	Node			*it_before = it._ptr->prev;
	Node			*it_after = it._ptr->next;

	it_before->next = it_after;
	it_after->prev = it_before;
	delete it._ptr;
	this->_n--;
}

template <typename D>
void	List<D>::insertFront(const D &e)
{
	Iterator	first = this->begin();

	this->insert(first, e);
}

template <typename D>
void	List<D>::insertBack(const D &e)
{
	Iterator	last = this->end();

	this->insert(last, e);
}

template <typename D>
void	List<D>::eraseFront(void)
{
	Iterator	first = this->begin();

	this->erase(first);
}

template <typename D>
void	List<D>::eraseBack(void)
{
	Iterator	last = --this->end();

	this->erase(last);
}

template <typename D>
void	List<D>::print(void) const
{
	for (Iterator beg = this->begin(); beg != this->end(); ++beg)
		std::cout << *beg << std::endl;
}

#endif
