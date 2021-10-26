/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:40:34 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 23:26:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringArrayPositionalList.hpp"

int	main(void)
{
	StringArrayPositionalList	seq;

	seq.insertBack(std::string("f1Ecs"));
	seq.insertBack(std::string("NU7Py"));
	seq.insertBack(std::string("Gq9"));
	seq.insertBack(std::string("Peh"));
	seq.insertBack(std::string("Mz8Yh"));
	seq.insertBack(std::string("MGtBq"));
	seq.insertBack(std::string("l20Yb"));
	seq.print();
	
	StringArrayPositionalList::SortedIterator	it = seq.beginSorted();
	
	for (int i = 0; i < 7; i++)
	{
		std::cout << i << ": " << *it << std::endl;
		++it;
	}
}
