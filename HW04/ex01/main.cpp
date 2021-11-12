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

template <typename E>
int	ft_tree_nullcount(const IBinaryTree<E> &tree);

int	main(void)
{
	srand(time(0));
	LinkedBinaryTree<int*>	tree;
	int	*ptrs[10] = {};

	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2)
			ptrs[i] = NULL;
		else
		{
			ptrs[i] = new int;
			*(ptrs[i]) = i; 
		}
	}
	std::cout << "Generated the following entries:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ":";
		if (ptrs[i])
		{
			std::cout << *(ptrs[i]);
		}
		else
		{
			std::cout << ptrs[i];
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}
