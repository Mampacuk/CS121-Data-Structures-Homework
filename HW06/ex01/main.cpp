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

#include "BSTMap.hpp"
#include <string>
#include <ctime>
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

void	ft_print_entries(BSTMap<double, int> &bst)
{
	auto keys = bst.keys();
	auto vals = bst.values();
	auto it1 = keys.begin();
	auto it2 = vals.begin();

	for ( ; it1 != keys.end(); ++it1, ++it2)
		std::cout << " " << *it1 << " : " << *it2 << std::endl;
}

int	main()
{
	BSTMap<int, std::string>	map;

	map.put(1, "Daria");
	map.put(2, "Jane");
	map.put(3, "Kevin");
	map.put(4, "Jodie");
	map.put(5, "Quinn");

	std::cout << "Made bunch of insertions from American cartoon sitcom `Daria`. (size=" << map.size() << ")" << std::endl;
	std::cout << "Starting to list them with a for loop by passing keys from 5 to 1:" << std::endl;
	for (int i = 5; i > 0; i--)
		std::cout << map.at(i) << std::endl;
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
	map.erase(5);
	std::cout << "Now let's get a container of the values to make sure she's still not there:" << std::endl;
	{
		auto values = map.values();
		std::cout << "\t";
		for (auto it = values.begin(); it != values.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	std::cout << "Tbh Kevin kinda misses his girlfriend Brittany so let's put her next to him (sorry Jane, but you have to go):" << std::endl;
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

	BSTMap<int, int>	ints(new SumsOfDigits);

	ints.put(5, 5);
	ints.put(4, 4);
	ints.put(3, 3);

	std::cout << std::endl << std::endl << "a'ight let's do custom comparator, such as SumOfDigits" << std::endl;
	std::cout << "at(111) yields value: " << ints.at(111) << std::endl;
	std::cout << "at(1000002) yields value: " << ints.at(1000002) << std::endl;
	std::cout << "calling erase(32)" << std::endl;
	ints.erase(32);
	auto entries = ints.entries();
	for (auto it = entries.begin(); it != entries.end(); ++it)
		std::cout << (*it)->getKey() << " : " << (*it)->getValue() << std::endl;
{
	srand(time(0));
	BSTMap<double, int>	bst;
	for (int i = 0; i < 20; i++)
		bst.put(static_cast<double>(rand()) / static_cast<double>(RAND_MAX), rand() % 100 - 49);
	std::cout << std::endl << "Commencing BST testing. let's create a random one, with 20 entries (size=" << bst.size() << "):" << std::endl;
	ft_print_entries(bst);
	std::cout << "Let's remove at most 10 entries, generated randomly by using ceil/floor:" << std::endl;
	/*
	 * Now can your Java do this? I know it can't, that's why it's a rhetorical question 
	 */
	IMap<double, int>::Entry	*(BSTMap<double, int>::*func[])(const double&) const =
	{
		&BSTMap<double, int>::ceilingEntry,
		&BSTMap<double, int>::floorEntry,
		&BSTMap<double, int>::higherEntry,
		&BSTMap<double, int>::lowerEntry
	};
	const char	*func_name[] =
	{
		"ceiling",
		"floor",
		"higher",
		"lower"
	};
	for (int i = 0; i < 10; i++)
	{
		double k = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		int f = rand() % 4;
		auto entry = (bst.*func[f])(k);
		std::cout << "First entry: " << bst.firstEntry()->getKey() << " : " << bst.firstEntry()->getValue() << ", last entry: " << bst.lastEntry()->getKey() << " : " << bst.lastEntry()->getValue() << std::endl;
		std::cout << " Generated key is " << k << std::endl;
		std::cout << " " << func_name[f] << " entry is ";
		if (entry)
		{
			std::cout << entry->getKey() << " : " << entry->getValue() << std::endl;
			bst.erase(entry->getKey());
		}
		else
			std::cout << "(null)" << std::endl;
	}
	std::cout << "The map after removals:" << std::endl;
	ft_print_entries(bst);
	std::cout << "Let's do 3 submaps and that's it, because it's 12:38AM already and I wanna sleep:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		double k1;
		double k2;

		do { k1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX); k2 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX); }
		while (k1 > k2);
		auto smap = bst.submap(k1, k2);
		std::cout << "Submap from " << k1 << " to " << k2 << ":" << std::endl;
		for (auto it = smap.begin(); it != smap.end(); ++it)
			std::cout << " " << (*it)->getKey() << " : " << (*it)->getValue() << std::endl;
	}
}
}
