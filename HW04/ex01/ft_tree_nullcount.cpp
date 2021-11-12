/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_nullcount.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:55:01 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/11 00:55:01 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/IBinaryTree.hpp"

template <typename E>
int	ft_tree_nullcount(const IBinaryTree<E> &tree)
{
	return (ft_subtree_nullcount(tree.root()));
}

template <typename E>
int	ft_subtree_nullcount(IBinaryTree<E>::Node *tree_node)
{
	if (!tree_node)
		return (0);
	return ((*(*tree_node) == NULL) + ft_subtree_nullcount(tree_node->left())
		+ ft_subtree_nullcount(tree_node->right()));
}
