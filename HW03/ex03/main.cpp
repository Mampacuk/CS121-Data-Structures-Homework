/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:25:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 18:32:35 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"
#include "DLLList.hpp"

/*
 * PLEASE READ "README.md" FOR CLARIFICATIONS!
 */
int	main(void)
{
	DLLList<int>	seq;

	seq.insert(seq.size(), 0);
	seq.insert(seq.size(), 1);
	seq.insert(seq.size(), 2);
	seq.insert(seq.size(), 3);
	seq.insert(seq.size(), 4);
	seq.insert(seq.size(), 5);
	std::cout << "Forward walk:" << std::endl;
	DLLList<int>::Iterator	fwd = seq.begin();
	for (int i = 0; i < 3; i++)
	{
		std::cout << *fwd << std::endl;
		++fwd;
	}
	std::cout << "Backward walk:" << std::endl;
	DLLList<int>::Iterator	rev = seq.end();
	for (int i = 0; i < 3; i++)
	{
		std::cout << *rev << std::endl;
		--rev;
	}
}
