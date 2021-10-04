/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:37:40 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 19:56:52 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DoublyLinkedList.hpp"

int	main(void)
{
	DoublyLinkedList<int>	*list;

	list = new DoublyLinkedList<int>;
	std::cout << "Adding 3, 1, -10 from front:" << std::endl;
	list->addFront(3);
	list->addFront(1);
	list->addFront(-10);
	list->print();
	std::cout << "Front is " << list->front() << " and back is " << list->back() << std::endl;
	std::cout << "Popping from front 3 times:" << std::endl;
	list->removeFront();
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
	std::cout << "Popping from front 3 times:" << std::endl;
	list->removeBack();
	list->removeBack();
	list->removeBack();
	list->print();
	
	std::cout << "Added 42 and 9 from back." << std::endl;
	list->addBack(42);
	list->addBack(9);
	DoublyLinkedList<int>	*copy = new DoublyLinkedList<int>(*list);
	std::cout << "Printing the copied list:" << std::endl;
	copy->print();
	
	delete copy;
	delete list;
}
