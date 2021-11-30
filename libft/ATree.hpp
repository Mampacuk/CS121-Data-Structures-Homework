/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:56:59 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/30 18:56:59 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATREE_HPP
# define ATREE_HPP

# include "ITree.hpp"

template <typename E>
class	ATree : virtual public ITree<E>
{
	public:
		class	Node : virtual public ITree<E>::Node
		{
			public:
				bool	isRoot(void)		const
				{
					return (!this->parent());
				}
				bool	isInternal(void)	const
				{
					return (this->numberOfChildren() > 0);
				}
				bool	isExternal(void)	const
				{
					return (!this->numberOfChildren());
				}
				virtual	~Node(void) {}
		};
		bool				empty(void)		const
		{
			return (!this->size());
		}
		virtual				~ATree(void) {}
};

#endif
