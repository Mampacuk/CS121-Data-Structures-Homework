/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:42:47 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 21:15:26 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayDeque.hpp"
#include <string>

int	main(void)
{
	ArrayDeque<std::string>	disenchantment(3);
	
	std::cout << "Luci entered the bar of Wonderland." << std::endl;
	disenchantment.insertFront(std::string("Luci"));
	disenchantment.print();
	std::cout << "Darn demon! Forgot to take the booze. He left from the front." << std::endl;
	disenchantment.eraseFront();
	disenchantment.print();
	std::cout << "Luci grabbed a cigarette on the way and enters from the back of the bar." << std::endl;
	disenchantment.insertBack(std::string("Luci"));
	disenchantment.print();
	std::cout << "Beanie needed his help in fighting monsters so he left from the back." << std::endl;
	disenchantment.eraseBack();
	disenchantment.print();
	std::cout << "Instead, Elfo entered the bar from front. 'Hi, I`m Elfo!', he said." << std::endl;
	disenchantment.insertFront(std::string("Elfo"));
	disenchantment.print();
	std::cout << "...And left immediately from back when he realized he's being chased by Sorcerio." << std::endl;
	disenchantment.eraseBack();
	disenchantment.print();
	std::cout << "Sorcerio entered from back to get Elfo`s magic blood." << std::endl;
	disenchantment.insertBack(std::string("Sorcerio"));
	disenchantment.print();
	std::cout << "Left from the front, when there was no sign of Elfo." << std::endl;
	disenchantment.eraseFront();
	disenchantment.print();
}