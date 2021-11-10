/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBinaryTree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:26:42 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/09 18:26:42 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IBINARYTREE_HPP
# define IBINARYTREE_HPP

# include "ITree.hpp"

template <typename E>
class	IBinaryTree : virtual public ITree<E>
{
	public:
		class	IBinaryNode : virtual public ITree<E>::Node
		{
			virtual IBinaryNode		*left(void)		const = 0;
			virtual IBinaryNode		*right(void)	const = 0;
			virtual IBinaryNode		*sibling(void)	const = 0;
		};
};

#endif