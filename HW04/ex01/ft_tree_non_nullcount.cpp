/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_non_nullcount.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:07:00 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/13 23:07:00 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/ITree.hpp"
#include "../../libft/DynamicArrayDeque.hpp"

/*
 * You can bring this in the header in the ../../libft folder,
 * if you wish to use templates to introduce generics. Otherwise
 * settle for the less :) (parametrized over int * only)
 */

static int	ft_subtree_non_nullcount(typename ITree<int*>::Node *tree_node)
{
	int	valid_pointers = 0;

	if (!tree_node)
		return (0);
	List<typename ITree<int*>::Node *>	family = tree_node->children();
	for (List<typename ITree<int*>::Node *>::Iterator it = family.begin();
			it != family.end();
			++it)
		valid_pointers += ft_subtree_non_nullcount(*it);
	return ((*(*tree_node) != NULL) + valid_pointers);
}

int	ft_tree_non_nullcount_recursive(const ITree<int*> &tree)
{
	return (ft_subtree_non_nullcount(tree.root()));
}

int	ft_tree_non_nullcount_iterative(const ITree<int*> &tree)
{
	int										result;
	DynamicArrayDeque<ITree<int*>::Node*>	deque;

	result = 0;
	deque.insertFront(tree.root());
	while (!deque.empty())
	{
		List<typename ITree<int*>::Node *>	family = deque.front()->children();
		for (List<typename ITree<int*>::Node *>::Iterator it = family.begin();
				it != family.end();
				++it)
			deque.insertBack(*it);
		if (*(*(deque.front())))
				result++;
		deque.eraseFront();
	}
	return (result);
}
