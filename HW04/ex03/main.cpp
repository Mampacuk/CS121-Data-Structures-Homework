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

int	main(void)
{
	LinkedBinaryTree<int>	tree;

	tree.addRoot(1);
	tree.addLeft(tree.root(), 2);
	// tree.addRight(tree.root(), 3);
	tree.print();
	tree.remove(tree.root());
	tree.print();
	tree.addLeft(tree.root(), 5);
	tree.addLeft(tree.root()->left(), 4);
	tree.addLeft(tree.root()->left()->left(), 6);
	tree.addRight(tree.root()->left()->left(), 7);
	tree.print();
	tree.remove(tree.root()->left());
	tree.print();
	List<ITree<int>::Node*>	nodes = tree.nodes();

	for (List<ITree<int>::Node*>::Iterator	it = nodes.begin();
		it != nodes.end();
		++it)
		std::cout << *(*(*it)) << std::endl;
	
	for (LinkedBinaryTree<int>::Iterator it = tree.begin();
		it != tree.end();
		++it)
		std::cout << *(*(*it)) << std::endl;
}
