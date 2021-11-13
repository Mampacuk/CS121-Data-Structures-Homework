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

#include "../../libft/libft.hpp"

int	ft_tree_nullcount_recursive(const IBinaryTree<int*> &tree);
int	ft_tree_nullcount_iterative(const IBinaryTree<int*> &tree);

/*
 * This program features random generation: you can (should) run it multiple times to correct the work
 */
int	main(void)
{
	srand(time(0));
	LinkedBinaryTree<int*>	tree;
	int						*ptrs[10] = {};
	int						null_count = 0;

	for (int i = 0; i < 10; i++)
	{
		if (!(rand() % 2))
		{
			ptrs[i] = new int;
			*(ptrs[i]) = i; 
		}
		else
			null_count++;
	}
	std::cout << "Generated the following entries:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ":";
		if (ptrs[i])
			std::cout << *(ptrs[i]);
		else
			std::cout << "(null)";
		std::cout << " ";
	}
	std::cout << std::endl;
	tree.addRoot(ptrs[0]);
	tree.addLeft(tree.root(), ptrs[1]);
	tree.addRight(tree.root(), ptrs[2]);
	tree.addLeft(tree.root()->left(), ptrs[3]);
	tree.addRight(tree.root()->left(), ptrs[4]);
	tree.addLeft(tree.root()->right(), ptrs[5]);
	tree.addRight(tree.root()->right(), ptrs[6]);
	tree.addLeft(tree.root()->left()->left(), ptrs[7]);
	tree.addRight(tree.root()->left()->left(), ptrs[8]);
	tree.addLeft(tree.root()->left()->right(), ptrs[9]);
	std::cout << std::endl << "The constructed tree is:" << std::endl;
	tree.print();
	int	result = ft_tree_nullcount_recursive(tree);
	std::cout << std::endl << "ft_tree_nullcount_recursive() returned " << result << std::endl;
	if (null_count == result)
		std::cout << ">>>>>>> SUCCESS <<<<<<<" << std::endl;
	else
		std::cout << ">>>>>>> FAILURE <<<<<<<" << std::endl;
	result = ft_tree_nullcount_iterative(tree);
	std::cout << std::endl << "ft_tree_nullcount_iterative() returned " << result << std::endl;
	if (null_count == result)
		std::cout << ">>>>>>> SUCCESS <<<<<<<" << std::endl;
	else
		std::cout << ">>>>>>> FAILURE <<<<<<<" << std::endl;
}
