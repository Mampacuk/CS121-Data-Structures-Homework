/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedBinaryTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:41:46 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/30 19:13:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDBINARYTREE
# define LINKEDBINARYTREE

# include "ABinaryTree.hpp"
# include "IIterator.hpp"

# include <exception>

template <typename E>
class	LinkedBinaryTree : public ABinaryTree<E>
{
	public:
		class	Node : public ABinaryTree<E>::BinaryNode
		{
			public:
				~Node(void);
				Node(const Node &copy) : _data(copy._data), _par(copy._par), _left(copy._left), _right(copy._right) {}
				E				&operator*(void);
				Node			&operator=(const Node &rhs);
				Node			*left(void)			const;
				Node			*right(void)		const;
				Node			*parent(void)		const;
				void			setElement(const E &e);
				void			addLeft(const E &e);
				void			addRight(const E &e);
				void			remove(void);
				friend class	LinkedBinaryTree;
			private:
				Node(void) : _data(), _par(NULL), _left(NULL), _right(NULL), _tree(NULL) {}
				Node(E &_data, LinkedBinaryTree *_tree) : _data(_data), _par(NULL), _left(NULL), _right(NULL), _tree(_tree) {}
				Node				*_par;
				Node				*_left;
				Node				*_right;
				LinkedBinaryTree	*_tree;
				E					_data;
		};
		class	Iterator : public IIterator<E>
		{
			public:
				Iterator(const Iterator &copy);
				~Iterator(void);
				Iterator		&operator=(const Iterator &rhs);
				E				&operator*(void);
				bool			operator==(const IIterator<E> &p)	const;
				bool			operator!=(const IIterator<E> &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
			private:
				Iterator(List<Node> *nodes);
				List<Node>						*_nodes;
				typename List<Node>::Iterator	_iter;
		};
		LinkedBinaryTree(void);
		~LinkedBinaryTree(void);
		LinkedBinaryTree(const LinkedBinaryTree &copy);
		LinkedBinaryTree	&operator=(const LinkedBinaryTree &rhs);
		int					size(void)				const;
		Node				*root(void)				const;
		List<Node>			*nodes(void)			const;
		Iterator			begin(void)				const;
		void				addRoot(const E &e);
	private:
		void				destruct(Node *root);
		void				inorder(const Node &p, List<Node> &snapshot) const;
		Node				*_root;
		int					_n;
};

// LinkedBinaryTree::Node

template <typename E>
LinkedBinaryTree<E>::Node::~Node(void)
{
	delete this->_left;
	delete this->_right;
}

template <typename E>
typename LinkedBinaryTree<E>::Node	&LinkedBinaryTree<E>::Node::operator=(const Node &rhs)
{
	this->_data = rhs._data;
	this->_par = rhs._par;
	this->_left = rhs._left;
	this->_right = rhs._right;
	this->_tree = rhs._tree;
	return (*this);
}

template <typename E>
E	&LinkedBinaryTree<E>::Node::operator*(void)
{
	return (this->_data);
}

template <typename E>
typename LinkedBinaryTree<E>::Node	*LinkedBinaryTree<E>::Node::left(void) const
{
	return (this->_left);
}

template <typename E>
typename LinkedBinaryTree<E>::Node	*LinkedBinaryTree<E>::Node::right(void) const
{
	return (this->_right);
}

template <typename E>
typename LinkedBinaryTree<E>::Node	*LinkedBinaryTree<E>::Node::parent(void) const
{
	return (this->_par);
}

template <typename E>
void	LinkedBinaryTree<E>::Node::setElement(const E &e)
{
	this->_data = e;
}

template <typename E>
void	LinkedBinaryTree<E>::Node::addLeft(const E &e)
{
	if (!this->_tree)
		throw std::logic_error("node operated is not a part of a tree");
	if (this->_left)
		throw std::logic_error("attempting to overwrite an already existing left child");
	this->_left = new Node(e, this->_tree);
	this->_tree->_n++;
}

template <typename E>
void	LinkedBinaryTree<E>::Node::addRight(const E &e)
{
	if (!this->_tree)
		throw std::logic_error("node operated is not a part of a tree");
	if (this->_right)
		throw std::logic_error("attempting to overwrite an already existing right child");
	this->_right = new Node(e, this->_tree);
	this->_tree->_n++;
}

/**
 * @brief removes the node from its tree and replaces with its child, if any,
 * and frees its memory; trying to operate on it will result in undefined
 * behavior
 * 
 * @tparam E 
 */
template <typename E>
void	LinkedBinaryTree<E>::Node::remove(void)
{
	if (this->_left && this->_right)
		throw std::logic_error("node operated on is no longer in a tree");
	Node	child = (this->_left ? this->_left : this->_right);
	if (child)
		child._par = this->_par;
	if (this == this->_tree->_root)
		this->_tree->_root = child;
	else
	{
		Node	parent = this->_par;
		if (this == parent._left)
			parent._left = child;
		else
			parent._right = child;
	}
	this->_tree->_n--;
	this->_left = NULL;
	this->_right = NULL;
	this->_tree = NULL;
	this->_par = NULL;
}

// LinkedBinaryTree::Iterator

template <typename E>
LinkedBinaryTree<E>::Iterator::Iterator(List<Node> *nodes) : _nodes(nodes), _iter(_nodes->begin()) {}

template <typename D>
LinkedBinaryTree<D>::Iterator::Iterator(const Iterator &copy) : _nodes(new List<Node>(copy._nodes)), _iter(_nodes->begin()) {}

template <typename D>
typename LinkedBinaryTree<D>::Iterator	&LinkedBinaryTree<D>::Iterator::operator=(const Iterator &rhs)
{
	this->_nodes = rhs._nodes;
	this->_iter = rhs._iter;
}

template <typename D>
LinkedBinaryTree<D>::Iterator::~Iterator(void)
{
	delete this->_nodes;
}

template <typename E>
bool	LinkedBinaryTree<E>::Iterator::operator==(const IIterator<E> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	return (*this->_iter == *it._iter);
}

template <typename E>
bool	LinkedBinaryTree<E>::Iterator::operator!=(const IIterator<E> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	return (*this->_iter != *it._iter);
}

template <typename E>
E	&LinkedBinaryTree<E>::Iterator::operator*(void)
{
	return (*this->_iter);
}

template <typename D>
typename LinkedBinaryTree<D>::Iterator	&LinkedBinaryTree<D>::Iterator::operator++(void)
{
	++this->_iter;
	return (*this);
}

template <typename D>
typename LinkedBinaryTree<D>::Iterator	&LinkedBinaryTree<D>::Iterator::operator--(void)
{
	--this->_iter;
	return (*this);
}

// LinkedBinaryTree

template <typename E>
LinkedBinaryTree<E>::LinkedBinaryTree(void) : _root(NULL), _n(0) {}

template <typename E>
int	LinkedBinaryTree<E>::size(void) const
{
	return (this->_n);
}

template <typename E>
typename LinkedBinaryTree<E>::Node	*LinkedBinaryTree<E>::root(void) const
{
	return (this->_root);
}

template <typename E>
void	LinkedBinaryTree<E>::addRoot(const E &e)
{
	if (!this->empty())
		throw std::logic_error("cannot add root to a non-empty tree");
	this->_root = new Node(e, this);
	this->_n = 1;
}

template <typename E>
void	LinkedBinaryTree<E>::inorder(const Node &p, List<Node> &snapshot) const
{
	if (p._left)
		this->inorder(p._left, snapshot);
	snapshot.insertBack(p);
	if (p._right)
		this->inorder(p._right, snapshot);
}

template <typename E>
List<typename LinkedBinaryTree<E>::Node>	*LinkedBinaryTree<E>::nodes(void) const
{
	List<Node>	*snapshot = new List<Node>;
	if (!this->empty())
		this->inorder(*this->_root, snapshot);
	return (snapshot);
}

template <typename E>
typename LinkedBinaryTree<E>::Iterator	LinkedBinaryTree<E>::begin(void) const
{
	return (Iterator(this->nodes()));
}

template <typename E>
void	LinkedBinaryTree<E>::destruct(Node *root)
{
	this->destruct(root->_left);
	this->destruct(root->_right);
	delete root;
}

template <typename E>
LinkedBinaryTree<E>::~LinkedBinaryTree(void)
{
	this->destruct(this->_root);
}

#endif
