/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABinaryTree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:44:22 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/30 19:06:47 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABINARYTREE
# define ABINARYTREE

# include "ATree.hpp"
# include "IBinaryTree.hpp"

template <typename E>
class	ABinaryTree : virtual public ATree<E>, virtual public IBinaryTree<E>
{
	public:
		class	BinaryNode : virtual public ATree<E>::Node, virtual public IBinaryTree<E>::IBinaryNode
		{
			public:
				BinaryNode	*sibling(void)		const
				{
					if (!this->parent())
						return (NULL);
					if (this == this->parent()->left())
						return (this->parent()->right());
					return (this->parent()->left());
				}
				bool	isExternal(void)	const
				{
					return (!this->left() && !this->right());
				}
				List<BinaryNode>	*children(void)
				{
					List<BinaryNode>	*family = new List<BinaryNode>;

					if (this->left())
						family->insertBack(*this->left());
					if (this->right())
						family->insertBack(*this->right());
					return (family);
				}
				virtual	~BinaryNode(void) {}
		};
		virtual				~ABinaryTree(void) {}
};

#endif
