/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:20:01 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 19:54:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SinglyLinkedList.hpp"

int	main(void)
{
	SinglyLinkedList<int>	*list;

	list = new SinglyLinkedList<int>;
	std::cout << "Adding 3, 1, -10 from front:" << std::endl;
	list->addFront(3);
	list->addFront(1);
	list->addFront(-10);
	list->print();
	std::cout << "Front is " << list->front() << " and back is " << list->back() << std::endl;
	std::cout << "Popping from front 2 times:" << std::endl;
	list->removeFront();
	list->removeFront();
	list->print();
	std::cout << "Adding 199, 42, 42, 9 from back:" << std::endl;
	list->addBack(199);
	list->addBack(42);
	list->addBack(42);
	list->addBack(9);
	list->print();
	std::cout << "Front is " << list->front() << " and back is " << list->back() << std::endl;
	std::cout << "Popping from front 4 times:" << std::endl;
	list->removeLast();
	list->removeLast();
	list->removeLast();
	list->removeLast();
	list->print();
	std::cout << "Adding 42 and 9 from back." << std::endl;
	list->addBack(42);
	list->addBack(9);
	SinglyLinkedList<int>	*copy = new SinglyLinkedList<int>(*list);
	std::cout << "Printing the copied list:" << std::endl;
	copy->print();
	
	delete copy;
	delete list;
}