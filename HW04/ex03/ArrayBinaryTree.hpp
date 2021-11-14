/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayBinaryTree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:07:27 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/13 12:07:27 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYBINARYTREE_HPP
# define ARRAYBINARYTREE_HPP

# include "../../libft/IBinaryTree.hpp"
# include "../../libft/IIterator.hpp"
# include "../../libft/DynamicArrayDeque.hpp"
# include "../../libft/ArrayVector.hpp"
# include "../../libft/libft.hpp"

# define DEFAULT_TREE_CAPACITY 17

template <typename E>
class	ArrayBinaryTree : public IBinaryTree<E>
{
	public:
		class	Node : public IBinaryTree<E>::Node
		{
			public:
				virtual ~Node(void) {}
				Node(const Node &copy) : _par(copy._par), _left(copy._left), _right(copy._right), _data(copy._data) {}
				E					&operator*(void)	const;
				Node				*left(void)			const;
				Node				*right(void)		const;
				Node				*sibling(void)		const;
				Node				*parent(void)		const;
				bool				isRoot(void)		const;
				bool				isExternal(void)	const;
				bool				isInternal(void)	const;
				int					height(void)		const;
				int					depth(void)			const;
				void				setElement(const E &e);
				List<typename ITree<E>::Node*>
					children(void)						const;
				friend class		ArrayBinaryTree;
			private:
				int					depth(Node *ptr)	const;
				int					height(Node *ptr)	const;
				Node(void) {}
				Node(int _i, E _data, ArrayVector<Node*> &_nodes) : _i(_i), _data(_data), _nodes(_nodes) {}
				int					_i;
				E					_data;
				ArrayVector<Node*>	&_nodes;
		}
		class	Iterator : public IIterator<typename ITree<E>::Node*>
		{
			public:
				Iterator(const Iterator &copy);
				~Iterator(void);
				Iterator		&operator=(const Iterator &rhs);
				typename ITree<E>::Node*	
								&operator*(void)											const;
				bool			operator==(const IIterator<typename ITree<E>::Node*> &p)	const;
				bool			operator!=(const IIterator<typename ITree<E>::Node*> &p)	const;
				Iterator		&operator++(void);
				Iterator		&operator--(void);
				friend class	ArrayBinaryTree;
			private:
				Iterator(List<typename ITree<E>::Node*> nodes);
				List<typename ITree<E>::Node*>						_nodes;
				typename List<typename ITree<E>::Node*>::Iterator	_iter;
		};
		ArrayBinaryTree(void);
		ArrayBinaryTree(int capacity);
		~ArrayBinaryTree(void) {}
		ArrayBinaryTree(const ArrayBinaryTree &copy);
		ArrayBinaryTree	&operator=(const ArrayBinaryTree &rhs);
		int					size(void)				const;
		bool				empty(void) 			const;
		Node				*root(void)				const;
		List<typename ITree<E>::Node*>
			nodes(void)								const;
		List<typename ITree<E>::Node*>
			preorder(void)							const;
		List<typename ITree<E>::Node*>
			postorder(void)							const;
		List<typename ITree<E>::Node*>
			inorder(void)							const;
		List<typename ITree<E>::Node*>
			breadthfirst(void)						const;
		Iterator			begin(void)				const;
		Iterator			end(void)				const;
		void				print(void)				const;
		int					height(void)			const;
		void				addRoot(const E &e);
		void				addLeft(Node *p, const E &e);
		void				addRight(Node *p, const E &e);
		void				remove(Node *p);
	private:
		void				print_node(const Node *root, int offset)						const;
		void				preorder(Node *p, List<typename ITree<E>::Node*> &snapshot)		const;
		void				postorder(Node *p, List<typename ITree<E>::Node*> &snapshot)	const;
		void				inorder(Node *p, List<typename ITree<E>::Node*> &snapshot)		const;
		ArrayVector<Node*>	_nodes;
		int					_n;
};

// ArrayBinaryTree::Node

template <typename E>
E	&ArrayBinaryTree<E>::Node::operator*(void) const
{
	return (this->_data);
}

template <typename E>
typename ArrayBinaryTree<E>::Node	*ArrayBinaryTree<E>::Node::left(void) const
{
	int	left = 2 * this->_i + 1;
	if (left >= this->_nodes.size())
		return (NULL);
	return (this->_nodes[left]);
}

template <typename E>
typename ArrayBinaryTree<E>::Node	*ArrayBinaryTree<E>::Node::right(void) const
{
	int	right = 2 * this->_i + 2;
	if (right >= this->_nodes.size())
		return (NULL);
	return (this->_nodes[right]);
}

template <typename E>
typename ArrayBinaryTree<E>::Node	*ArrayBinaryTree<E>::Node::parent(void) const
{
	if (this->isRoot())
		return (NULL);
	return (this->_nodes[(this->_i - 1) / 2]);
}

template <typename E>
typename ArrayBinaryTree<E>::Node	*ArrayBinaryTree<E>::Node::sibling(void) const
{
	if (!this->parent())
		return (NULL);
	if (this == this->parent()->left())
		return (this->parent()->right());
	return (this->parent()->left());
}

template <typename E>
List<typename ITree<E>::Node*>	ArrayBinaryTree<E>::Node::children(void) const
{
	List<typename ITree<E>::Node*>	family;

	if (this->left())
		family.insertBack(this->left());
	if (this->right())
		family.insertBack(this->right());
	return (family);
}

template <typename E>
bool	ArrayBinaryTree<E>::Node::isRoot(void) const
{
	return (!this->_i);
}

template <typename E>
bool	ArrayBinaryTree<E>::Node::isExternal(void) const
{
	return (!this->left() && !this->right());
}

template <typename E>
bool	ArrayBinaryTree<E>::Node::isInternal(void) const
{
	return (!this->isExternal());
}

template <typename E>
void	ArrayBinaryTree<E>::Node::setElement(const E &e)
{
	this->_data = e;
}

// ArrayBinaryTree::Iterator

template <typename E>
ArrayBinaryTree<E>::Iterator::Iterator(List<typename ITree<E>::Node*> nodes)
{
	this->_nodes = nodes;
	this->_nodes.insertBack(NULL);
	this->_iter = this->_nodes.begin();
}

template <typename D>
ArrayBinaryTree<D>::Iterator::Iterator(const Iterator &copy)
{
	this->_nodes = copy._nodes;
	this->_iter = this->_nodes.begin();
}

template <typename D>
typename ArrayBinaryTree<D>::Iterator	&ArrayBinaryTree<D>::Iterator::operator=(const Iterator &rhs)
{
	this->_nodes = rhs._nodes;
	this->_iter = rhs._iter;
}

template <typename D>
ArrayBinaryTree<D>::Iterator::~Iterator(void) {}

template <typename E>
bool	ArrayBinaryTree<E>::Iterator::operator==(const IIterator<typename ITree<E>::Node*> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	return (*this->_iter == *it._iter);
}

template <typename E>
bool	ArrayBinaryTree<E>::Iterator::operator!=(const IIterator<typename ITree<E>::Node*> &p) const
{
	if (typeid(p) != typeid(Iterator))
		throw std::bad_typeid();
	const Iterator	&it = dynamic_cast<const Iterator&>(p);
	return (*this->_iter != *it._iter);
}

template <typename E>
typename ITree<E>::Node*	&ArrayBinaryTree<E>::Iterator::operator*(void) const
{
	return (*this->_iter);
}

template <typename D>
typename ArrayBinaryTree<D>::Iterator	&ArrayBinaryTree<D>::Iterator::operator++(void)
{
	++this->_iter;
	return (*this);
}

template <typename D>
typename ArrayBinaryTree<D>::Iterator	&ArrayBinaryTree<D>::Iterator::operator--(void)
{
	--this->_iter;
	return (*this);
}

template <typename E>
ArrayBinaryTree<E>::ArrayBinaryTree(void) {}

template <typename E>
int	ArrayBinaryTree<E>::size(void) const
{
	return (this->_n);
}

template <typename E>
bool	ArrayBinaryTree<E>::empty(void) const
{
	return (!this->_n);
}

template <typename E>
typename ArrayBinaryTree<E>::Node	*ArrayBinaryTree<E>::root(void) const
{
	if (!this->_nodes.empty())
		return (this->_nodes[0]);
	return (NULL);
}

template <typename E>
void	ArrayBinaryTree<E>::addRoot(const E &e)
{
	if (!this->empty())
		throw std::logic_error("cannot add root to a non-empty tree");
	this->_nodes.insert(0, new Node(0, e, this->_nodes));
	this->_n = 1;
}

template <typename E>
void	ArrayBinaryTree<E>::preorder(Node *p, List<typename ITree<E>::Node*> &snapshot) const
{
	snapshot.insertBack(p);
	if (p->left())
		this->preorder(p->left(), snapshot);
	if (p->right())
		this->preorder(p->right(), snapshot);
}

template <typename E>
List<typename ITree<E>::Node*>	ArrayBinaryTree<E>::preorder(void) const
{
	List<typename ITree<E>::Node*>	snapshot;
	if (!this->empty())
		this->inorder(this->_root, snapshot);
	return (snapshot)
}

template <typename E>
void	ArrayBinaryTree<E>::postorder(Node *p, List<typename ITree<E>::Node*> &snapshot) const
{
	if (p->left())
		this->postorder(p->left(), snapshot);
	snapshot.insertBack(p);
	if (p->right())
		this->postorder(p->right(), snapshot);
}

template <typename E>
List<typename ITree<E>::Node*>	ArrayBinaryTree<E>::postorder(void) const
{
	List<typename ITree<E>::Node*>	snapshot;
	if (!this->empty())
		this->postorder(this->_root, snapshot);
	return (snapshot)
}

template <typename E>
void	ArrayBinaryTree<E>::inorder(Node *p, List<typename ITree<E>::Node*> &snapshot) const
{
	if (p->left())
		this->inorder(p->left(), snapshot);
	snapshot.insertBack(p);
	if (p->right())
		this->inorder(p->right(), snapshot);
}

template <typename E>
List<typename ITree<E>::Node*>	ArrayBinaryTree<E>::inorder(void) const
{
	List<typename ITree<E>::Node*>	snapshot;
	if (!this->empty())
		this->inorder(this->_root, snapshot);
	return (snapshot)
}

template <typename E>
List<typename ITree<E>::Node*>	ArrayBinaryTree<E>::breadthfirst(void) const
{
	DynamicArrayDeque<typename ITree<E>::Node*>	deque;
	List<typename ITree<E>::Node*>				snapshot;
	if (!this->empty())
	{
		deque.insertBack(this->root());
		while (!deque.empty())
		{
			IBinaryTree<int*>::Node	*front_node = dynamic_cast<IBinaryTree<int*>::Node*>(deque.front());
			if (front_node->left())
				deque.insertBack(front_node->left());
			if (front_node->right())
				deque.insertBack(front_node->right());
			snapshot.insertBack(deque.front());
			deque.eraseFront();
		}
	}
	return (snapshot);
}

template <typename E>
List<typename ITree<E>::Node*>	ArrayBinaryTree<E>::nodes(void) const
{
	return (this->preorder());
}

template <typename E>
typename ArrayBinaryTree<E>::Iterator	ArrayBinaryTree<E>::begin(void) const
{
	return (Iterator(this->nodes()));
}

template <typename E>
typename ArrayBinaryTree<E>::Iterator	ArrayBinaryTree<E>::end(void) const
{
	return (Iterator(List<typename ITree<E>::Node*>()));
}

template <typename E>
ArrayBinaryTree<E>::ArrayBinaryTree(void) : _n(0)
{
	for (int i = 0; i < DEFAULT_TREE_CAPACITY; i++)
		this->_nodes.insert(this->_nodes.size(), NULL);
}

template <typename E>
ArrayBinaryTree<E>::ArrayBinaryTree(int capacity) : _n(0)
{
	for (int i = 0; i < capacity; i++)
		this->_nodes.insert(this->_nodes.size(), NULL);
}

template <typename E>
void	ArrayBinaryTree<E>::addLeft(Node *p, const E &e)
{
	if (!p)
		return ;
	if (p->left())
		throw std::logic_error("attempting to overwrite an already existing left child");
	int	set_index = 2 * p->_i + 1;
	while (this->_nodes.size() < set_index)
		this->_nodes.insert(this->_nodes.size(), NULL);
	this->_nodes.set(set_index, new Node(set_index, e, this->_nodes));
	this->_n++;
}

template <typename E>
void	ArrayBinaryTree<E>::addRight(Node *p, const E &e)
{
	if (!p)
		return ;
	if (p->right())
		throw std::logic_error("attempting to overwrite an already existing right child");
	int	set_index = 2 * p->_i + 2;
	while (this->_nodes.size() < set_index)
		this->_nodes.insert(this->_nodes.size(), NULL);
	this->_nodes.set(set_index, new Node(set_index, e, this->_nodes));
	this->_n++;
}

template <typename E>
int	ArrayBinaryTree<E>::Node::depth(Node *ptr) const
{
	if (ptr->isRoot())
		return (0);
	return (1 + this->depth(ptr->parent()));
}

template <typename E>
int	ArrayBinaryTree<E>::Node::depth(void) const
{
	this->depth(this);
}

template <typename E>
int	ArrayBinaryTree<E>::Node::height(Node *ptr) const
{
	int	h;

	if (!ptr || ptr->isExternal())
		return (0);
	h = 0;
	h = ft_max(h, this->height(ptr->left()));
	h = ft_max(h, this->depth(ptr->right()));
	return (h + 1);
}

template <typename E>
void	ArrayBinaryTree<E>::remove(Node *p)
{
	if (!p)
		return ;
	if (p->left() && p->right())
		throw std::logic_error("cannot remove a node that has 2 children");
	DynamicArrayDeque<Node*>	deque;
	if (p->right())
		deque.insertBack(p->right());
	if (p->left())
		deque.insertBack(p->left());
	while (!deque.empty())
	{
		int		set_index;
		Node	*front = deque.front();
		if (front->left())
			deque.insertBack(front->left());
		if (front->right())
			deque.insertBack(front->right());
		set_index = (front->_i - 1) / 2 - (front->_i % 2);
		this->_nodes.set(set_index, front);
		front->_i = set_index;
		deque.eraseFront();
	}
	this->_n--;
	delete p;
}

template <typename E>
void	LinkedBinaryTree<E>::print_node(const Node *root, int offset) const
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
	this->print_node(this->root(), 0);
}

#endif
