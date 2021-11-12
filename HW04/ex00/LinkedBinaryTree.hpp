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

# include "../../libft/IBinaryTree.hpp"
# include "../../libft/IIterator.hpp"

# include <exception>

template <typename E>
class	LinkedBinaryTree : public IBinaryTree<E>
{
	public:
		class	Node : public IBinaryTree<E>::IBinaryNode
		{
			public:
				virtual ~Node(void) {}
				Node(const Node &copy) : _par(copy._par), _left(copy._left), _right(copy._right), _data(copy._data) {}
				E				&operator*(void);
				Node			&operator=(const Node &rhs);
				Node			*left(void)			const;
				Node			*right(void)		const;
				Node			*sibling(void)		const;
				Node			*parent(void)		const;
				List<typename ITree<E>::Node*>
					children(void)					const;
				List<typename ITree<E>::Node*>
					grandchildren(void)				const;
				bool			isRoot(void)		const;
				bool			isExternal(void)	const;
				bool			isInternal(void)	const;
				void			setElement(const E &e);
				friend class	LinkedBinaryTree;
			private:
				Node(void) : _par(NULL), _left(NULL), _right(NULL), _data() {}
				Node(const E &_data) : _par(NULL), _left(NULL), _right(NULL), _data(_data) {}
				Node				*_par;
				Node				*_left;
				Node				*_right;
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
		bool				empty(void) 			const;
		Node				*root(void)				const;
		List<typename ITree<E>::Node*>
			nodes(void)								const;
		Iterator			begin(void)				const;
		void				print(void)				const;
		void				addRoot(const E &e);
		void				addLeft(Node *p, const E &e);
		void				addRight(Node *p, const E &e);
		void				remove(Node *p);
	private:
		void				destruct(Node *root);
		void				print_node(Node *root, int offset)	const;
		void				inorder(Node *p, List<typename ITree<E>::Node*> &snapshot) const;
		Node				*_root;
		int					_n;
};

// LinkedBinaryTree::Node

template <typename E>
typename LinkedBinaryTree<E>::Node	&LinkedBinaryTree<E>::Node::operator=(const Node &rhs)
{
	this->_data = rhs._data;
	this->_par = rhs._par;
	this->_left = rhs._left;
	this->_right = rhs._right;
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
typename LinkedBinaryTree<E>::Node	*LinkedBinaryTree<E>::Node::sibling(void) const
{
	if (!this->_par)
		return (NULL);
	if (this == this->_par->_left)
		return (this->_par->_right);
	return (this->_par->_left);
}

template <typename E>
typename LinkedBinaryTree<E>::Node	*LinkedBinaryTree<E>::Node::parent(void) const
{
	return (this->_par);
}


template <typename E>
List<typename ITree<E>::Node*>	LinkedBinaryTree<E>::Node::children(void) const
{
	List<typename ITree<E>::Node*>	family;

	if (this->_left)
		family.insertBack(this->_left);
	if (this->_right)
		family.insertBack(this->_right);
	return (family);
}

template <typename E>
List<typename ITree<E>::Node*>	LinkedBinaryTree<E>::Node::grandchildren(void) const
{
	List<typename ITree<E>::Node*>	family;

	if (this->_left)
	{
		if (this->_left->_left)
			family.insertBack(this->_left->_left);
		if (this->_left->_right)
			family.insertBack(this->_left->_right);
	}
	if (this->_right)
	{
		if (this->_right->_left)
			family.insertBack(this->_right->_left);
		if (this->_right->_right)
			family.insertBack(this->_right->_right);
	}
	return (family);
}

template <typename E>
bool	LinkedBinaryTree<E>::Node::isRoot(void) const
{
	return (!this->_par);
}

template <typename E>
bool	LinkedBinaryTree<E>::Node::isExternal(void) const
{
	return (!this->_left && !this->_right);
}

template <typename E>
bool	LinkedBinaryTree<E>::Node::isInternal(void) const
{
	return (!this->isExternal());
}

template <typename E>
void	LinkedBinaryTree<E>::Node::setElement(const E &e)
{
	this->_data = e;
}

template <typename E>
std::ostream	&operator<<(std::ostream &o, const typename LinkedBinaryTree<E>::Node &n)
{
	o << *n;
	return (o);
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
bool	LinkedBinaryTree<E>::empty(void) const
{
	return (!this->_n);
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
	this->_root = new Node(e);
	this->_n = 1;
}

template <typename E>
void	LinkedBinaryTree<E>::inorder(Node *p, List<typename ITree<E>::Node*> &snapshot) const
{
	if (p->_left)
		this->inorder(p->_left, snapshot);
	snapshot.insertBack(p);
	if (p->_right)
		this->inorder(p->_right, snapshot);
}

template <typename E>
List<typename ITree<E>::Node*>	LinkedBinaryTree<E>::nodes(void) const
{
	List<typename ITree<E>::Node*>	snapshot;
	if (!this->empty())
		this->inorder(this->_root, snapshot);
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
	if (root)
	{
		this->destruct(root->_left);
		this->destruct(root->_right);
	}
	delete root;
}

template <typename E>
LinkedBinaryTree<E>::~LinkedBinaryTree(void)
{
	this->destruct(this->_root);
}

template <typename E>
void	LinkedBinaryTree<E>::addLeft(Node *p, const E &e)
{
	if (!p)
		return ;
	if (p->_left)
		throw std::logic_error("attempting to overwrite an already existing left child");
	p->_left = new Node(e);
	this->_n++;
}

template <typename E>
void	LinkedBinaryTree<E>::addRight(Node *p, const E &e)
{
	if (!p)
		return ;
	if (p->_right)
		throw std::logic_error("attempting to overwrite an already existing right child");
	p->_right = new Node(e);
	this->_n++;
}

/**
 * @brief removes the node from its tree and replaces with its child, if any,
 * and frees its memory; trying to operate on it will result in undefined
 * behavior
 * 
 * @tparam E 
 */
template <typename E>
void	LinkedBinaryTree<E>::remove(Node *p)
{
	if (!p)
		return ;
	if (p->_left && p->_right)
		throw std::logic_error("cannot remove a node that has 2 children");
	Node	*child = (p->_left ? p->_left : p->_right);
	if (child)
		child->_par = p->_par;
	if (p == this->_root)
		this->_root = child;
	else
	{
		Node	*parent = p->_par;
		if (p == parent._left)
			parent._left = child;
		else
			parent._right = child;
	}
	this->_n--;
	delete p;
}


template <typename E>
void	LinkedBinaryTree<E>::print_node(Node *root, int offset) const
{
	if (!root)
		return ;
	for (int i = 0; i < offset; i++)
		std::cout << "  ";
	std::cout << **root;
	if (root->isInternal())
		std::cout << " ( " ;
	std::cout << std::endl;
	this->print_node(root->left(), offset + 2);
	this->print_node(root->right(), offset + 2);
	if (root->isInternal())
	{
		for (int i = 0; i < offset + 1; i++)
			std::cout << "  ";
		std::cout << ")" << std::endl;
	}
}

template <typename E>
void	LinkedBinaryTree<E>::print(void) const
{
	if (this->empty())
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	std::cout << "size: " << this->_n << std::endl;
	this->print_node(this->_root, 0);
}

#endif
