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

#include "UnsortedSLLMap.hpp"
#include <string>
#include <iostream>

class	SumsOfDigits : public IComparator<int>
{
	public:
		bool	operator()(const int &a, const int &b) const
		{
			return (this->compute(a) == this->compute(b));
		}
	private:
		int	compute(int nb) const
		{
			if (nb < 0)
				nb *= -1;
			if (nb < 10)
				return (nb);
			return (compute(nb / 10) + compute(nb % 10));
		}
};

int	main()
{
	UnsortedSLLMap<int, std::string>	map;

	map.insert(1, "Daria");
	map.insert(2, "Jane");
	map.insert(3, "Kevin");
	map.insert(4, "Jodie");
	map.insert(5, "Quinn");

	std::cout << "Made bunch of insertions from American sitcom cartoon `Daria`. (size=" << map.size() << ")" << std::endl;
	std::cout << "Starting to list them with a for loop by passing keys from 5 to 1:" << std::endl;
	for (int i = 5; i > 0; i--)
		std::cout << (*map.find(i))->getKey() << " : " << (*map.find(i))->getValue() << std::endl;
	std::cout << "Actually, Jodie is gonna have her own show. It was announced in 2020, it's gonna be called `Jodie`. She's gotta go." << std::endl;
	map.erase(4);
	std::cout << "Now let's get a container of the keys to make sure she's still not there:" << std::endl;
	{
		auto keys = map.keys();
		std::cout << "\t";
		for (auto it = keys.begin(); it != keys.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	std::cout << "Indeed, size now is " << map.size() << ", and, Quinn's gotta go to shopping so we can see how deletion at the head of SLL works." << std::endl;
	map.erase(map.find(5));
	std::cout << "Now let's get a container of the values to make sure she's still not there:" << std::endl;
	{
		auto values = map.values();
		std::cout << "\t";
		for (auto it = values.begin(); it != values.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	std::cout << "Tbh Kevin kinda misses his girlfriend Brittany so let's put her next to him (sorry Jane, but you'll have to go):" << std::endl;
	map.put(2, "Brittany");
	{
		auto entries = map.entries();
		for (auto it = entries.begin(); it != entries.end(); ++it)
			std::cout << (*it)->getKey() << " : " << (*it)->getValue() << std::endl;
	}
	std::cout << "K let's wrap up, i'll take the keys to remove the rest:" << std::endl;
	auto keys = map.keys();
	for (auto it = keys.begin(); it != keys.end(); ++it)
		map.erase(*it);
	std::cout << "The size indeed is " << map.size() << " and empty() yields " << map.empty();

	UnsortedSLLMap<int, int>	ints(new SumsOfDigits);

	ints.insert(5, 5);
	ints.insert(4, 4);
	ints.insert(3, 3);

	std::cout << std::endl << std::endl << "a'ight let's do custom comparator, such as SumOfDigits" << std::endl;
	std::cout << "at(111) yields value: " << ints.at(111) << std::endl;
	std::cout << "at(1000002) yields value: " << ints.at(1000002) << std::endl;
	std::cout << "calling erase(32)" << std::endl;
	ints.erase(32);
	auto entries = ints.entries();
	for (auto it = entries.begin(); it != entries.end(); ++it)
		std::cout << (*it)->getKey() << " : " << (*it)->getValue() << std::endl;
}
