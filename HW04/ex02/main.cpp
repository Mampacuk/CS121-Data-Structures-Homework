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
#include "Integer.hpp"

bool	ft_isproper_btree(Integer **arr, int arr_len);

/*
 * This program features random generation: you can (should) run it multiple times to correct the work
 */
int	main(void)
{
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		int		tree_size;
		Integer	**ptrs;

		tree_size = rand() % 10 + 1;
		ptrs = new Integer *[tree_size];
		for (int j = 0; j < tree_size; j++)
		{
			if (!(rand() % 2))
				ptrs[j] = new Integer;
			else
				ptrs[j] = NULL;
		}
		std::cout << "Generated the following entries:" << std::endl;
		for (int j = 0; j < tree_size; j++)
		{
			std::cout << j << ":";
			if (ptrs[j])
				std::cout << ptrs[j];
			else
				std::cout << "(null)";
			std::cout << " ";
		}
		std::cout << std::endl << "ft_isproper_btree() returned: ";
		if (ft_isproper_btree(ptrs, tree_size))
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
		std::cout << std::endl;
		/*
		 * cleaning up memory because I'm not irresponsible and/or lazy
		 */
		for (int j = 0; j < tree_size; j++)

			delete ptrs[j];
		delete [] ptrs;
	}
}
