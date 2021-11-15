/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:20:30 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/13 12:20:30 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"
#include "ArrayBinaryTree.hpp"

int	main(void)
{
	std::cout << "Let's observe LinkedBinaryTree first, then see ArrayBinaryTree mimicing it" << std::endl;
	LinkedBinaryTree<int>	linked_tree;

	linked_tree.addRoot(1);
	linked_tree.addLeft(linked_tree.root(), 2);
	linked_tree.print();
	linked_tree.remove(linked_tree.root());
	linked_tree.print();
	linked_tree.addLeft(linked_tree.root(), 5);
	linked_tree.addLeft(linked_tree.root()->left(), 4);
	linked_tree.addLeft(linked_tree.root()->left()->left(), 6);
	linked_tree.addRight(linked_tree.root()->left()->left(), 7);
	linked_tree.print();
	linked_tree.remove(linked_tree.root()->left());
	std::cout << "Removed node 5:" << std::endl;
	linked_tree.print();

	std::cout << "Traversing using nodes:" << std::endl;
	List<ITree<int>::Node*>	linked_nodes = linked_tree.nodes();
	for (List<ITree<int>::Node*>::Iterator	it = linked_nodes.begin();
		it != linked_nodes.end();
		++it)
		std::cout << *(*(*it)) << std::endl;
	std::cout << "Traversing using iterator:" << std::endl;
	for (LinkedBinaryTree<int>::Iterator it = linked_tree.begin();
		it != linked_tree.end();
		++it)
		std::cout << *(*(*it)) << std::endl;
	
	std::cout << std::endl << "Now, watch ArrayBinaryTree:" << std::endl;
	ArrayBinaryTree<int>	array_tree;

	array_tree.addRoot(1);
	array_tree.addLeft(array_tree.root(), 2);
	array_tree.print();
	array_tree.remove(array_tree.root());
	array_tree.print();
	array_tree.addLeft(array_tree.root(), 5);
	array_tree.addLeft(array_tree.root()->left(), 4);
	array_tree.addLeft(array_tree.root()->left()->left(), 6);
	array_tree.addRight(array_tree.root()->left()->left(), 7);
	array_tree.print();
	array_tree.remove(array_tree.root()->left());
	std::cout << "Removed node 5:" << std::endl;
	array_tree.print();

	std::cout << "Traversing using nodes (preorder):" << std::endl;
	List<ITree<int>::Node*>	array_nodes = array_tree.nodes();
	for (List<ITree<int>::Node*>::Iterator	it = array_nodes.begin();
		it != array_nodes.end();
		++it)
			std::cout << *(*(*it)) << ", its depth is " << dynamic_cast<ArrayBinaryTree<int>::Node*>(*it)->depth() << std::endl;
	std::cout << "Traversing using iterator:" << std::endl;
	for (ArrayBinaryTree<int>::Iterator it = array_tree.begin();
		it != array_tree.end();
		++it)
		std::cout << *it << std::endl;
	std::cout << "Traversing inorder:" << std::endl;
	List<ITree<int>::Node*>	inorder = array_tree.inorder();
	for (List<ITree<int>::Node*>::Iterator	it = inorder.begin();
		it != inorder.end();
		++it)
		std::cout << *(*(*it)) << std::endl;
	std::cout << "Traversing postorder:" << std::endl;
	List<ITree<int>::Node*>	postorder = array_tree.postorder();
	for (List<ITree<int>::Node*>::Iterator	it = postorder.begin();
		it != postorder.end();
		++it)
		std::cout << *(*(*it)) << std::endl;
	std::cout << "Traversing breadthfirst:" << std::endl;
	List<ITree<int>::Node*>	breadthfirst = array_tree.breadthfirst();
	for (List<ITree<int>::Node*>::Iterator	it = breadthfirst.begin();
		it != breadthfirst.end();
		++it)
		std::cout << *(*(*it)) << std::endl;

	std::cout << "after " << **array_tree.root()->left()->left() << " comes " << **array_tree.inorderAfter(array_tree.root()->left()->left()) << std::endl;
}
