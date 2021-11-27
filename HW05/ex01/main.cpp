/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:06:56 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 18:06:56 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"
#include <vector>
#include <ctime>
#include <iostream>

Triangle	ft_generate_triangle(void)
{
	int	a;
	int	b;
	int	c;

	do
	{
		a = rand() % 15 + 1;
		b = rand() % 15 + 1;
		c = rand() % 15 + 1;
	} while (!(a + b > c && a + c > b && b + c > a));
	return (Triangle(a, b, c));
}

int	main(void)
{
	srand(time(0));

	std::vector<Triangle>	triangles1;
	triangles1.reserve(5);
	
	for (int i = 0; i < 5; i++)
		triangles1.push_back(ft_generate_triangle());
	std::cout << "Generated the following entries:" << std::endl;
	std::cout << "_______________________________" << std::endl;
	for (std::vector<Triangle>::iterator it = triangles1.begin(); it != triangles1.end(); ++it)
		std::cout << *it;

	std::vector<Triangle>	triangles2(triangles1);
	
	std::sort(triangles1.begin(), triangles1.end());
	std::cout << std::endl << "After using C++'s sort (default comparator):" << std::endl;
	std::cout << "___________________________________________" << std::endl;
	for (std::vector<Triangle>::iterator it = triangles1.begin(); it != triangles1.end(); ++it)
		std::cout << *it;

	std::sort(triangles2.begin(), triangles2.end(), Triangle::AreaComparator());
	std::cout << std::endl << "After using C++'s sort (custom area comparator):" << std::endl;
	std::cout << "_______________________________________________" << std::endl;
	for (std::vector<Triangle>::iterator it = triangles2.begin(); it != triangles2.end(); ++it)
		std::cout << *it;
}