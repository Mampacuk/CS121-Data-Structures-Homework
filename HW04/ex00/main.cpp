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

// #include "LinkedBinaryTree.hpp"
#include "../../libft/libft.hpp"

int	main(void)
{
	LinkedBinaryTree<bool>	tree;

	LinkedBinaryTree<bool>::Node *treeroot = tree.root();
	if (!treeroot)
		std::cout << "null" << std::endl;
	tree.addRoot(true);
	std::cout << tree.size();
}
