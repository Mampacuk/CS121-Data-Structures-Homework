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

#include "DynamicArrayDeque.hpp"
#include <string>

int	main(void)
{
	DynamicArrayDeque<std::string>	disenchantment(1);
	
	std::cout << "Luci entered the bar of Wonderland he stole a long time ago." << std::endl;
	disenchantment.insertFront(std::string("Luci"));
	disenchantment.print();
	std::cout << "Darn demon! Forgot to take the booze with him. He left from the front." << std::endl;
	disenchantment.eraseFront();
	disenchantment.print();
	std::cout << "Luci grabbed a cigarette on the way back and entered from the back of the bar." << std::endl;
	disenchantment.insertBack(std::string("Luci"));
	disenchantment.print();
	std::cout << "Beanie needed his help in fighting the ogres so he left from the back." << std::endl;
	disenchantment.eraseBack();
	disenchantment.print();
	std::cout << "Instead, Elfo entered the bar from front. 'Hi, I`m Elfo!', he mumbled, waving his tiny hand." << std::endl;
	disenchantment.insertFront(std::string("Elfo"));
	disenchantment.print();
	std::cout << "...And left immediately from back when he realized he's being chased by Sorcerio." << std::endl;
	disenchantment.eraseBack();
	disenchantment.print();
	std::cout << "Sorcerio entered from back to get Elfo`s magic blood for Zog's Elixir of Life." << std::endl;
	disenchantment.insertBack(std::string("Sorcerio"));
	disenchantment.print();
	std::cout << "Sorcerio left from the front, when there was no sign of Elfo." << std::endl;
	disenchantment.eraseFront();
	disenchantment.print();
	std::cout << "Zog entered from front with a hope to find Beanie who was avoiding another wedding. Arch-Druidess followed him, along with Pendergast." << std::endl;
	disenchantment.insertFront(std::string("Zog"));
	disenchantment.insertFront(std::string("Arch-Druidess"));
	disenchantment.insertFront(std::string("Pendergast"));
	disenchantment.print();
	std::cout << "King Zog left, Pendergast too." << std::endl;
	disenchantment.eraseFront();
	disenchantment.eraseBack();
	disenchantment.print();
	std::cout << "And Tiabeanie rushed in, from back." << std::endl;
	disenchantment.insertBack(std::string("Tiabeanie"));
	disenchantment.print();
	std::cout << "Arch-Druidess turned out to be an antagonist and attempted to shoot Beanie dead. Beanie dodged, and the villain left." << std::endl;
	disenchantment.eraseFront();
	disenchantment.print();
	std::cout << "Beanie rushed out to kick her ass in Steamland." << std::endl;
	disenchantment.eraseBack();
	disenchantment.print();
	std::cout << "After the squad came back, and Bean revealed her magical powers, they gathered together last time in the bar." << std::endl;
	disenchantment.insertBack(std::string("Tiabeanie"));
	disenchantment.insertFront(std::string("Luci"));
	disenchantment.insertBack(std::string("Elfo"));
	disenchantment.insertFront(std::string("Zog"));
	disenchantment.insertBack(std::string("Odval"));
	disenchantment.insertBack(std::string("Oona"));
	disenchantment.print();
	disenchantment.eraseFront();
	disenchantment.eraseFront();
	disenchantment.print();
}