/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:19:58 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/09 14:19:58 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedBinaryTree.hpp"
#include "../../libft/libft.hpp"

void	ft_print_grandchildren(const List<ITree<int>::Node*> &gc)
{
	for (List<ITree<int>::Node*>::Iterator it = gc.begin();
			it != gc.end();
			++it)
	{
		LinkedBinaryTree<int>::Node	*node = dynamic_cast<LinkedBinaryTree<int>::Node*>(*it);
		std::cout << *(*node) << std::endl;
	}
}

int	main(void)
{
	LinkedBinaryTree<int>	tree;

	tree.addRoot(1);

	List<ITree<int>::Node*>	gc0 = tree.root()->grandchildren();
	if (gc0.begin() == gc0.end())
		std::cout << "gc0 is empty" << std::endl;

	LinkedBinaryTree<int>::Node	*root = tree.root();
	tree.addLeft(root, 2);
	tree.addLeft(root->left(), 4);
	tree.addRight(root->left(), 5);
	tree.addRight(root->left()->right(), -1);

	List<ITree<int>::Node*>	gc1 = tree.root()->grandchildren();
	if (gc1.begin() != gc1.end())
		std::cout << "gc1 isn't empty" << std::endl;
	ft_print_grandchildren(gc1);

	tree.addRight(root, 3);
	tree.addLeft(root->right(), 6);

	std::cout << "tree size is " << tree.size() << std::endl << "gc2:" << std::endl;
	List<ITree<int>::Node*>	gc2 = tree.root()->grandchildren();
	ft_print_grandchildren(gc2);

	tree.addRight(root->right(), 7);

	std::cout << "gc3:" << std::endl;
	List<ITree<int>::Node*>	gc3 = tree.root()->grandchildren();
	ft_print_grandchildren(gc3);

	tree.print();
}
