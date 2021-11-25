/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:03:59 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/24 16:03:59 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/SortedPriorityQueue.hpp"
#include "MaxPriorityQueue.hpp"

int	main(void)
{
	{
		SortedPriorityQueue<int, std::string>	hi;

		hi.print();
		std::cout << "size:" << hi.size() << std::endl;
		hi.insert(0, "hi");
		hi.insert(0, "hello");
		hi.insert(163, "how");
		hi.insert(-20, "are you");
		hi.insert(7, "i'm big");
		hi.insert(163, "cake is a lie");
		hi.insert(-1, "me not");
		hi.insert(100, "me just 100");
		hi.insert(1, "hello world");
		hi.print();
		std::cout << "min is " << hi.min()->getKey() << ":" << hi.min()->getValue() << std::endl;
		std::cout << "Removed min" << std::endl;
		hi.removeMin();
		std::cout << "min is " << hi.min()->getKey() << ":" << hi.min()->getValue() << std::endl;
		hi.print();
		std::cout << "Removed min" << std::endl;
		hi.removeMin();
		std::cout << "min is " << hi.min()->getKey() << ":" << hi.min()->getValue() << std::endl;
	}
	std::cout << std::endl;
	{
		MaxPriorityQueue<std::string>	hi;

		hi.print();
		std::cout << "size:" << hi.size() << std::endl;
		hi.insert(0, "hi");
		hi.insert(0, "hello");
		hi.insert(163, "how");
		hi.insert(-20, "are you");
		hi.insert(7, "i'm big");
		hi.insert(163, "cake is a lie");
		hi.insert(-1, "me not");
		hi.insert(100, "me just 100");
		hi.insert(1, "hello world");
		hi.print();
		std::cout << "max is " << hi.max()->getKey() << ":" << hi.max()->getValue() << std::endl;
		std::cout << "Removed max" << std::endl;
		hi.removeMax();
		std::cout << "max is " << hi.max()->getKey() << ":" << hi.max()->getValue() << std::endl;
		hi.print();
		std::cout << "Removed max" << std::endl;
		hi.removeMax();
		std::cout << "max is " << hi.max()->getKey() << ":" << hi.max()->getValue() << std::endl;
	}
}