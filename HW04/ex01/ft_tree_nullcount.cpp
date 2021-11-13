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
#include "../../libft/DynamicArrayDeque.hpp"

/*
 * You can bring this in the header in the ../../libft folder,
 * if you wish to use templates to introduce generics. Otherwise
 * settle for the less :) (parametrized over int* only)
 */

static int	ft_subtree_nullcount(typename IBinaryTree<int*>::Node *tree_node)
{
	if (!tree_node)
		return (0);
	return ((*(*tree_node) == NULL) + ft_subtree_nullcount(tree_node->left())
		+ ft_subtree_nullcount(tree_node->right()));
}

int	ft_tree_nullcount_recursive(const IBinaryTree<int*> &tree)
{
	return (ft_subtree_nullcount(dynamic_cast<IBinaryTree<int*>::Node*>(tree.root())));
}

int	ft_tree_nullcount_iterative(const IBinaryTree<int*> &tree)
{
	int										result;
	DynamicArrayDeque<ITree<int*>::Node*>	deque;

	result = 0;
	deque.insertFront(tree.root());
	while (!deque.empty())
	{
		IBinaryTree<int*>::Node	*front_node = dynamic_cast<IBinaryTree<int*>::Node*>(deque.front());
		if (front_node->left())
			deque.insertBack(front_node->left());
		if (front_node->right())
			deque.insertBack(front_node->right());
		if (*(*front_node) == NULL)
			result++;
		deque.eraseFront();
	}
	return (result);
}
