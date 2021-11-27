/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:45:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 16:45:02 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>
#include <chrono>
#include "../../libft/libft.hpp"

int	ft_generate_key(int nb)
{
	if (nb < 0)
		nb *= -1;
	if (nb < 10)
		return (nb);
	return (ft_generate_key(nb / 10) + ft_generate_key(nb % 10));
}

/*
 * run `bash tester.sh`, `./tester.sh` (make sure to `chmod` the x rights),
 * or `make test` to input 1,000 numbers using `seq` tool (`man seq`)
 */
int	main(void)
{
	std::unordered_map<int, int>	hashmap;
	int								val;
	int								key;
	double							diff;
	std::cout << "INPUT 1,000 INTEGERS." << std::endl;
	for (int i = 0; i < 1000; i++)
	{
		std::cin >> val;
		if (std::cin.fail())
		{
			std::cout << "INVALID INPUT. SHAME ON YOU" << std::endl;
			return (1);
		}
		key = ft_generate_key(val);
		if (hashmap.find(key) == hashmap.end())
			hashmap.insert({key, val});
	}
	std::cout << std::endl << "AFTER INSERTION, THE HASHMAP CONTAINS";
	for (auto it = hashmap.begin(); it != hashmap.end(); it++)
		std::cout << ", " << it->first << ":" << it->second;
	std::cout << std::endl;

	std::cout << std::endl << "COMMENCING TESTING OF UNSORTED PRIORITY QUEUE..." << std::endl;
	auto upq_start = std::chrono::high_resolution_clock::now();
	UnsortedPriorityQueue<int, int>	upq;
	for (auto it = hashmap.begin(); it != hashmap.end(); it++)
		upq.insert(it->first, it->second);
	std::cout << "Output";
	auto upq_insertion = std::chrono::high_resolution_clock::now();
	while (!upq.empty())
	{
		std::cout << ", " << upq.min()->getValue();
		upq.removeMin();
	}
	auto upq_end = std::chrono::high_resolution_clock::now();

	std::cout << std::endl << std::endl << "COMMENCING TESTING OF SORTED PRIORITY QUEUE..." << std::endl;
	auto spq_start = std::chrono::high_resolution_clock::now();
	SortedPriorityQueue<int, int>	spq;
	for (auto it = hashmap.begin(); it != hashmap.end(); it++)
		spq.insert(it->first, it->second);
	std::cout << "Output";
	auto spq_insertion = std::chrono::high_resolution_clock::now();
	while (!spq.empty())
	{
		std::cout << ", " << spq.min()->getValue();
		spq.removeMin();
	}
	auto spq_end = std::chrono::high_resolution_clock::now();
	
	std::cout << std::endl << std::endl << "COMMENCING TESTING OF HEAP PRIORITY QUEUE..." << std::endl;
	auto hpq_start = std::chrono::high_resolution_clock::now();
	HeapPriorityQueue<int, int>	hpq;
	for (auto it = hashmap.begin(); it != hashmap.end(); it++)
		hpq.insert(it->first, it->second);
	auto hpq_insertion = std::chrono::high_resolution_clock::now();
	std::cout << "Output";
	while (!hpq.empty())
	{
		std::cout << ", " << hpq.min()->getValue();
		hpq.removeMin();
	}
	auto hpq_end = std::chrono::high_resolution_clock::now();

	std::cout << std::endl << "___________________________" << std::endl << std::endl << std::fixed;
	std::cout << "RESULTS:" << std::endl << std::endl;
	std::cout << "Unsorted Priority Queue" << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(upq_insertion - upq_start).count()) / 1000000.0;
	std::cout << "Insertion time: " << diff << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(upq_end - upq_insertion).count()) / 1000000.0;
	std::cout << "Removal time: " << diff << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(upq_end - upq_start).count()) / 1000000.0;
	std::cout << "TOTAL: " << diff << std::endl << std::endl;

	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(spq_insertion - spq_start).count()) / 1000000.0;
	std::cout << "Sorted Priority Queue" << std::endl;
	std::cout << "Insertion time: " << diff << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(spq_end - spq_insertion).count()) / 1000000.0;
	std::cout << "Removal time: " << diff << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(spq_end - spq_start).count()) / 1000000.0;
	std::cout << "TOTAL: " << diff << std::endl << std::endl;

	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(hpq_insertion - hpq_start).count()) / 1000000.0;
	std::cout << "Heap Priority Queue" << std::endl;
	std::cout << "Insertion time: " << diff << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(hpq_end - hpq_insertion).count()) / 1000000.0;
	std::cout << "Removal time: " << diff << std::endl;
	diff = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(hpq_end - hpq_start).count()) / 1000000.0;
	std::cout << "TOTAL: " << diff << std::endl << std::endl;
}