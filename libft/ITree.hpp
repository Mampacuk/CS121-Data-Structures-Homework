/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:31:14 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/09 13:31:14 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITREE_HPP
# define ITREE_HPP

# include "List.hpp"

template <typename E>
class	ITree
{
	public:
		class	Node
		{
			public:
				virtual E			&operator*(void) 	const = 0;
				virtual Node		*parent(void)		const = 0;
				virtual List<Node*>	children(void)		const = 0;
				virtual bool		isRoot(void)		const = 0;
				virtual bool		isExternal(void)	const = 0;
		};
		virtual int			size(void)		const = 0;
		virtual bool		empty(void)		const = 0;
		virtual Node		*root(void)		const = 0;
		virtual List<Node*>	nodes(void)		const = 0;
};

#endif