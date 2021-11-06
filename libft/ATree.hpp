/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:46:44 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/30 19:07:03 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATREE
# define ATREE

# include "ArrayVector.hpp"

template <typename E>
class	ATree
{
	public:
		class	Node
		{
			public:
				E			&operator*(void);
				Node		parent(void)		const;
				List<Node>	children(void)		const;
				bool		isRoot(void)		const;
				bool		isExternal(void)	const;
		};
		int			size(void)		const;
		bool		empty(void)		const;
		Node		root(void)		const;
		List<Node>	nodes(void)	const;
};

#endif
