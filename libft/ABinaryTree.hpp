/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABinaryTree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:09:18 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/30 19:09:18 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABINARYTREE_HPP
# define ABINARYTREE_HPP

# include "ATree.hpp"
# include "IBinaryTree.hpp"

template <typename E>
class	ABinaryTree : virtual public ATree<E>, virtual public IBinaryTree<E>
{
	public:
		class	Node : virtual public ATree<E>::Node, virtual public IBinaryTree<E>::Node
		{
			public:
				typename IBinaryTree<E>::Node	*sibling(void) const
				{
					if (!this->parent())
						return (NULL);
					if (this == dynamic_cast<Node*>(this->parent())->left())
						return (dynamic_cast<Node*>(this->parent())->right());
					return (dynamic_cast<Node*>(this->parent())->left());
				}
				int			numberOfChildren(void) const
				{
					return ((this->left() != NULL) + (this->right() != NULL));
				}
				List<typename ITree<E>::Node*>	children(void) const
				{
					List<typename ITree<E>::Node*>	family;

					if (this->left())
						family.insertBack(this->left());
					if (this->right())
						family.insertBack(this->right());
					return (family);
				}
				virtual	~Node(void) {}
		};
		virtual				~ABinaryTree(void) {}
};

#endif