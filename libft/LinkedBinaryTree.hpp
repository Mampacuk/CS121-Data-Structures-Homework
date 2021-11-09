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

template <typename E>
class	LinkedBinaryTree : public ABinaryTree<E>
{
	protected:
		struct	Node
		{
			E		data;
			Node	*par;
			Node	*left;
			Node	*right;
			Node(void) : data(), par(NULL), left(NULL), right(NULL) {}
		}
	public:
		class	Position : public ABinaryTree::Position<E>
		{
			public:
				Position(void) : _node(NULL) {}
				~Position(void) {}
				Position(const Position &copy);
				Position		&operator=(const Position &rhs);
				E				&operator*(void);
				Position		left(void)			const;
				Position		right(void)			const;
				Position		parent(void)		const;
				bool			isRoot(void)		const;
				bool			isExternal(void)	const;
				friend class	LinkedBinaryTree;
			private:
				Position(Node *_node) : _node(_node) {}
				Node	*_node;
		}
		LinkedBinaryTree(void);
		~LinkedBinaryTree(void);
		LinkedBinaryTree(const LinkedBinaryTree &copy);
		LinkedBinaryTree	&operator=(const LinkedBinaryTree &rhs);
		int					size(void)				const;
		bool				empty(void)				const;
		Position			root(void)				const;
		List<Position>		positions(void)			const;
		void				addRoot(E &e)			const;
		void				expandExternal(const Position &p);
		Position			removeAboveExternal(const Position &p);
	protected:
		void				preorder(Node *v, List<Position> &pl)	const;
	private:
		Node				*_root;
		int					_n;
};

// LinkedBinaryTree::Position

template <typename E>
LinkedBinaryTree<E>::Position::Position(const Position &copy) : _node(copy._node)

template <typename E>
typename LinkedBinaryTree<E>::Position	&LinkedBinaryTree<E>::Position::operator=(const Position &rhs)
{
	this->_node = copy._node;
	return (*this);
}

template <typename E>
E	&LinkedBinaryTree<E>::Position::operator*(void)
{
	return (this->node->data);
}

template <typename E>
typename LinkedBinaryTree<E>::Position	LinkedBinaryTree<E>::Position::left(void) const
{
	return (this->node->left);
}

template <typename E>
typename LinkedBinaryTree<E>::Position	LinkedBinaryTree<E>::Position::right(void) const
{
	return (this->node->right);
}

template <typename E>
typename LinkedBinaryTree<E>::Position	LinkedBinaryTree<E>::Position::parent(void) const
{
	return (this->node->parent);
}

template <typename E>
bool	LinkedBinaryTree<E>::Position::isRoot(void) const
{
	return (!this->node->parent);
}

template <typename E>
bool	LinkedBinaryTree<E>::Position::isExternal(void) const
{
	return (!this->node->left && !this->node->right);
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
	return (!this->size());
}

template <typename E>
LinkedBinaryTree<E>::Position	LinkedBinaryTree<E>::root(void) const
{
	return (Position(this->_root));
}

template <typename E>
void	LinkedBinaryTree<D>::addRoot(void)
{
	this->_root = new Node;
	
}

#endif
