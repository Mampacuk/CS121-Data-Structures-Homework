/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:47:19 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 14:45:45 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef List_HPP
# define List_HPP

# include "IList.hpp"
# include <iostream>

template <typename D>
class	List : public IList<D>
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
				Iterator(const Iterator &copy);
				Iterator		&operator=(const Iterator &rhs);
				D				&operator*(void);
				//bool			operator==(const List<D>::Iterator &p)	const;
				//bool			operator!=(const List<D>::Iterator &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
				friend class	List;	// don't want to use `friend`!!
			private:
				Iterator(Node *node);
				bool			equals(const IIterator<D> &rhs)	const; 
				void			insert(const D &e);
				void			erase(void);
				Node			*_ptr; 
		};
		List(void);
		~List(void);
		List(const List &copy);
		List				&operator=(const List &rhs);
		int					size(void)	const;
		bool				empty(void)	const;
		List<D>::Iterator	begin(void)	const;
		List<D>::Iterator	end(void)	const;
		void				print(void)	const;
		void				insertFront(const D &e);
		void				insertBack(const D &e);
		void				insert(IIterator<D> &p, const D &e);
		void				eraseFront(void);
		void				eraseBack(void);
		void				erase(Iterator &p);
	private:
		int					_n;
		Node				*_header;
		Node				*_trailer;
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
bool	List<D>::Iterator::equals(const IIterator<D> &rhs)	const
{
	const Iterator	&it = dynamic_cast<const Iterator&>(rhs);
	
	return (this->_ptr == it._ptr);
}

template <typename D>
D	&List<D>::Iterator::operator*(void)
{
	return (this->_ptr->data);
}

//template <typename D>
//bool	List<D>::Iterator::operator==(const List<D>::Iterator &p) const
//{
//	return (this->_ptr == p._ptr);
//}

//template <typename D>
//bool	List<D>::Iterator::operator!=(const List<D>::Iterator &p) const
//{
//	return (this->_ptr != p._ptr);
//}

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
void	List<D>::Iterator::insert(const D &e)
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
void	List<D>::Iterator::erase(void)
{
	Node	*it_before = this->_ptr->prev;
	Node	*it_after = this->_ptr->next;

	it_before->next = it_after;
	it_after->prev = it_before;
	delete this->_ptr;
	this->_ptr = it_after;
}

template <typename D>
List<D>::List(void)
{
	this->_n = 0;
	this->_header = new Node;
	this->_trailer = new Node;
	this->_header->next = this->_trailer;
	this->_trailer->prev = this->_header;
	// std::cout << "trailer at " << this->_trailer << std::endl;
	// std::cout << "header at " << this->_header << std::endl;
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
void	List<D>::insert(IIterator<D> &p, const D &e)
{
	const Iterator	&it = dynamic_cast<Iterator&>(p);

	// dummy code
	//
	(void)it;
	(void)e;
	// dummy code
	this->_n++;
}

template <typename D>
void	List<D>::erase(Iterator &p)
{
	p.erase();
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
