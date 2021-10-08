/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:06:16 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:34 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayQueue.hpp"
#include <string>

int	main(void)
{
	ArrayQueue<std::string>	left4dead2;

	std::cout << "Louis has found some pills. The queue's size is " << left4dead2.size() << std::endl;
	std::cout << "Is it empty? " << left4dead2.empty() << std::endl;

	left4dead2.enqueue(std::string("Tank"));
	std::cout << "Tank smelled the pills and entered the queue. Is it empty? " << left4dead2.empty() << std::endl;
	std::cout << "The Spitter and Ellis also joined the queue to get medkits." << std::endl;
	left4dead2.enqueue(std::string("Spitter"));
	left4dead2.enqueue(std::string("Ellis"));
	std::cout << "The queue now is:" << std::endl;
	left4dead2.print();
	std::cout << "BUT Rochelle comes in. 'Axe me a question, I dare you!', she says, as Louis hands out 2 pills." << std::endl;
	left4dead2.enqueue(std::string("Rochelle"));
	left4dead2.dequeue();
	left4dead2.dequeue();
	std::cout << "The queue now is:" << std::endl;
	left4dead2.print();
	std::cout << "At the front is " << left4dead2.front() << std::endl;
}