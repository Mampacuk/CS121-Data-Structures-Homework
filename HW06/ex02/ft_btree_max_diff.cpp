/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_max_diff.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:18:52 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/09 18:18:52 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/LinkedBinaryTree.hpp"
#include "../../libft/IMap.hpp"
#include "../../libft/LinkedStack.hpp"
#include "BSTMap.hpp"

typedef LinkedBinaryTree<std::unique_ptr<IMap<int, int>::Entry>>::Node TreeNode;

TreeNode	*ft_separate_root(BSTMap<int, int> &tree)
{
	return (tree._tree.root());
}

static void	ft_draw_node(const TreeNode *root, int offset)
{
	if (!root)
		return ;
	for (int i = 0; i < offset; i++)
		std::cout << "  ";
	if ((**root).get())
		std::cout << (**root).get()->getKey();
	else
		std::cout << "(null)";
	if (root->isInternal())
		std::cout << " ( " ;
	std::cout << std::endl;
	ft_draw_node(root->left(), offset + 2);
	ft_draw_node(root->right(), offset + 2);
	if (root->isInternal())
	{
		for (int i = 0; i < offset + 1; i++)
			std::cout << "  ";
		std::cout << ")" << std::endl;
	}
}

void	ft_draw_tree(BSTMap<int, int> &tree)
{
	ft_draw_node(ft_separate_root(tree), 0);
}

static void	ft_calculate_diff(TreeNode *root, IStack<int> &stack, int &result)
{
	if (root->left())
		ft_calculate_diff(root->left(), stack, result);
	if (root->right())
		ft_calculate_diff(root->right(), stack, result);
	if ((**root).get())	// if the node's Entry reference is not null
	{
		int	numberOfChildren = ((**root->left()).get() != NULL) + ((**root->right()).get() != NULL);
		/*
		 * Check if it's REALLY external 
		 */
		if (numberOfChildren)	// if Entry has children
		{
			int	diff = 0;
			int	max = 0;
			for (int i = numberOfChildren; i > 0; i--)
			{
				diff = abs(diff - stack.top());
				if (stack.top() > max)
					max = stack.top();
				stack.pop();
			}
			stack.push(max + 1);
			if (diff > result)
				result = diff;
		}
		else		// if Entry doesn't have children
			stack.push(1);
	}
}

int	ft_btree_max_diff(BSTMap<int, int> &tree)
{
	int	result = 0;
	LinkedStack<int>	stack;
	ft_calculate_diff(ft_separate_root(tree), stack, result);
	return (result);
}
