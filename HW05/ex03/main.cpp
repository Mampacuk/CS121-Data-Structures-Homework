/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:32 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/26 13:51:32 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "../../libft/ArrayVector.hpp"
#include "PQEntry.hpp"

void	heapsort(ArrayVector<IPriorityQueue<char, char>::Entry*> &vector);

void	ft_print_keys(ArrayVector<IPriorityQueue<char, char>::Entry*> &vector)
{
	if (vector.empty())
	{
		std::cout << "(null)";
		return ;
	}
	std::cout << "(";
	for (int i = 0; i < vector.size() - 1; i++)
		std::cout << static_cast<int>(vector[i]->getKey()) << " ";
	std::cout << static_cast<int>(vector[vector.size() - 1]->getKey()) << ")";
}

static ArrayVector<IPriorityQueue<char, char>::Entry*>	ft_generate_vector(int size)
{
	ArrayVector<IPriorityQueue<char, char>::Entry*>	vector;

	for (int i = 0; i < size; i++)
		vector.insert(vector.size(), new PQEntry<char, char>(static_cast<char>(rand() % 95 + 32), static_cast<char>(0)));
	return (vector);
}

int	main(void)
{
	srand(time(0));
	for (int i = 1; i <= 10; i++)
	{
		ArrayVector<IPriorityQueue<char, char>::Entry*>	vector = ft_generate_vector(i);
		std::cout << "The vector generated -> the vector sorted: ";
		ft_print_keys(vector);
		std::cout << " -> ";
		heapsort(vector);
		ft_print_keys(vector);
		std::cout << std::endl;
	}
}