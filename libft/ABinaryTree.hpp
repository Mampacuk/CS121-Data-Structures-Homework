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

# include "List.hpp"

template <typename E>
class	ABinaryTree
{
	public:
		class	Node
		{
			public:
				E		&operator*(void);
				Node	left(void)			const;
				Node	right(void)			const;
				Node	parent(void)		const;
				bool	isRoot(void)		const;
				bool	isExternal(void)	const;
		};
		int			size(void)		const;
		bool		empty(void)		const;
		Node		root(void)		const;
		List<Node>	nodes(void)	const;
};

#endif
