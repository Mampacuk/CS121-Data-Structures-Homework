/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnsortedSLLMap.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:00:35 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/03 15:00:35 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSORTEDSLLMAP_HPP
# define UNSORTEDSLLMAP_HPP

# include "../../libft/AMap.hpp"
# include "../../libft/IIterator.hpp"
# include <exception>

template <typename K, typename V>
class	UnsortedSLLMap : public AMap<K, V>
{
	private:
		struct	Node
		{
			Node(typename AMap<K, V>::MapEntry *entry) : entry(entry), next(NULL) {}
			Node(typename AMap<K, V>::MapEntry *entry, Node *next) : entry(entry), next(next) {}
			~Node() { delete this->entry; }
			typename IMap<K, V>::Entry	*entry;
			Node						*next;
		};
		Node	*_head;
		int		_size;
	public:
		class	Iterator : public IIterator<typename IMap<K, V>::Entry*>
		{
			public:
				Iterator	&operator++() { this->_ptr = this->_ptr->next; return (*this); }
				typename IMap<K, V>::Entry*	&operator*()	const { return (this->_ptr->entry); }
				bool		operator==(const IIterator<typename IMap<K, V>::Entry*> &rhs)	const;
				bool		operator!=(const IIterator<typename IMap<K, V>::Entry*> &rhs)	const;
				Iterator	&operator--() { throw std::logic_error(
					"cannot walk backwards with a forward iterator"); return (*this); }
			private:
				Iterator(Node *_ptr) : _ptr(_ptr) {}
				Node	*_ptr;
				friend class UnsortedSLLMap;
		};
		UnsortedSLLMap() : AMap<K, V>(), _head(NULL), _size(0) {}
		explicit UnsortedSLLMap(IComparator<K> *comparator) : AMap<K, V>(comparator), _head(NULL), _size(0) {}
		~UnsortedSLLMap();
		int			size() const;
		V			&at(const K &key) const;
		Iterator 	find(const K &k) const;
		V			&put(const K &k, const V &v);
		Iterator	insert(const K &k, const V &v);
		void		erase(const K &k);
		void		erase(const IIterator<typename IMap<K, V>::Entry*> &p);
		Iterator	begin();
		Iterator	end();
		ArrayVector<typename IMap<K, V>::Entry*>	entries() const;
	private:
		Node		*locateNode(const K &k)	const;
};

template <typename K, typename V>
UnsortedSLLMap<K, V>::~UnsortedSLLMap()
{
	Node *curr = this->_head;

	while (curr)
	{
		Node	*next = curr->next;
		delete curr;
		curr = next;
	}
}

template <typename K, typename V>
int	UnsortedSLLMap<K, V>::size() const
{
	return (this->_size);
}

template <typename K, typename V>
bool	UnsortedSLLMap<K, V>::Iterator::operator==(const IIterator<typename IMap<K, V>::Entry*> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	return (this->_ptr == it._ptr);
}

template <typename K, typename V>
bool	UnsortedSLLMap<K, V>::Iterator::operator!=(const IIterator<typename IMap<K, V>::Entry*> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	return (this->_ptr != it._ptr);
}


template <typename K, typename V>
typename UnsortedSLLMap<K, V>::Iterator	UnsortedSLLMap<K, V>::insert(const K &k, const V &v)
{
	Iterator	finding = this->find(k);
	if (finding != this->end())
	{
		(*finding)->setValue(v);
		return (finding);
	}
	this->_head = new Node(new typename AMap<K, V>::MapEntry(k, v), this->_head);
	this->_size++;
	return (Iterator(this->_head));
}

template <typename K, typename V>
V	&UnsortedSLLMap<K, V>::put(const K &k, const V &v)
{
	return ((*this->insert(k, v))->getValue());
}

template <typename K, typename V>
typename UnsortedSLLMap<K, V>::Node	*UnsortedSLLMap<K, V>::locateNode(const K &k)	const
{
	Node	*curr = this->_head;
	while (curr)
	{
		if (this->equals(curr->entry->getKey(), k))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

template <typename K, typename V>
typename UnsortedSLLMap<K, V>::Iterator	UnsortedSLLMap<K, V>::begin()
{
	return (Iterator(this->_head));
}

template <typename K, typename V>
typename UnsortedSLLMap<K, V>::Iterator	UnsortedSLLMap<K, V>::end()
{
	return (Iterator(NULL));
}

template <typename K, typename V>
typename UnsortedSLLMap<K, V>::Iterator	UnsortedSLLMap<K, V>::find(const K &k) const
{
	return (Iterator(this->locateNode(k)));
}

template <typename K, typename V>
V	&UnsortedSLLMap<K, V>::at(const K &k) const
{
	typename IMap<K, V>::Entry	*ptr = *this->find(k);
	if (!ptr)
		throw std::out_of_range("no value found for the given key");
	return (ptr->getValue());
}

template <typename K, typename V>
void	UnsortedSLLMap<K, V>::erase(const K &k)
{
	Node *curr;
	
	if (!(curr = this->_head))
		return ;
	// case for the single head
	if (this->equals(curr->entry->getKey(), k))
	{
		this->_head = curr->next;
		delete curr;
		this->_size--;
		return ;
	}
	while (curr->next)
	{
		Node	*removed = curr->next;
		if (this->equals(removed->entry->getKey(), k))
		{
			curr->next = removed->next;
			delete removed;
			this->_size--;
			return ;
		}
		curr = curr->next;
	}
}

template <typename K, typename V>
void	UnsortedSLLMap<K, V>::erase(const IIterator<typename IMap<K, V>::Entry*> &p)
{
	this->erase((*p)->getKey());
}

template <typename K, typename V>
ArrayVector<typename IMap<K, V>::Entry*>	UnsortedSLLMap<K, V>::entries() const
{
	ArrayVector<typename IMap<K, V>::Entry*>	entries;
	Node	*curr = this->_head;

	while (curr)
	{
		entries.push_back(curr->entry);
		curr = curr->next;
	}
	return (entries);
}

#endif
