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
int		ft_btree_max_diff(BSTMap<int, int> &tree);

int	main()
{
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		BSTMap<int, int>	bst;
		for (int i = 0; i < 15; i++)
			bst.put(rand() % 30, 0);
		std::cout << "Created the following tree:" << std::endl;
		ft_draw_tree(bst);
		std::cout << std::endl << "MAXIMUM DIFFERENCE IS " << ft_btree_max_diff(bst) << std::endl << std::endl;
	}
}
