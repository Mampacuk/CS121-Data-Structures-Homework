/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:32:18 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/04 15:32:18 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSTMap.hpp"
#include <string>
#include <ctime>
#include <iostream>

void	ft_draw_tree(BSTMap<int, int> &tree);
template <typename K, typename V>
typename BSTMap<K, V>::Entry	*ft_bst_median(BSTMap<K, V> &tree);

int	main()
{
	srand(time(0));
	for (int j = 0; j < 3; j++)
	{
		BSTMap<int, int>	bst;
		for (int i = j; i < 5 + j; i++)
			bst.put(rand() % 30, 0);
		std::cout << "Created the following tree:" << std::endl;
		bst.draw_tree();
		auto ret = ft_bst_median<int, int>(bst);
		std::cout << std::endl << "MEDIAN ENTRY IS " << ret->getKey() << ":" << ret->getValue() << std::endl << std::endl;
	}
}
